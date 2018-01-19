#include "ofMesh.h"
#include "ofAppRunner.h"
#include <map>

//--------------------------------------------------------------
ofMesh::ofMesh(){
	mode = OF_PRIMITIVE_TRIANGLES;
	bVertsChanged = false;
	bColorsChanged = false;
	bNormalsChanged = false;
	bTexCoordsChanged = false;
	bIndicesChanged = false;
	bFacesDirty = false;
	useColors = true;
	useTextures = true;
	useNormals = true;
	useIndices = true;

}

//--------------------------------------------------------------
ofMesh::ofMesh(ofPrimitiveMode mode, const vector<ofVec3f>& verts){
	bColorsChanged = false;
	bNormalsChanged = false;
	bTexCoordsChanged = false;
	useColors = true;
	useTextures = true;
	useNormals = true;
	useIndices = true;
	setMode(mode);
	addVertices(verts);
}

//--------------------------------------------------------------
void ofMesh::clear(){
	if(!vertices.empty()){
		bVertsChanged = true;
		vertices.clear();
	}
	if(!colors.empty()){
		bColorsChanged = true;
		colors.clear();
	}
	if(!normals.empty()){
		bNormalsChanged = true;
		normals.clear();
	}
	if(!texCoords.empty()){
		bTexCoordsChanged = true;
		texCoords.clear();
	}
	if(!indices.empty()){
		bIndicesChanged = true;
		indices.clear();
	}
	bFacesDirty = true;
}

//--------------------------------------------------------------
bool ofMesh::haveVertsChanged(){
	if(bVertsChanged){
		bVertsChanged = false;
		return true;
	}else{
		return false;
	}
}

//--------------------------------------------------------------
bool ofMesh::haveColorsChanged(){
	if(bColorsChanged){
		bColorsChanged = false;
		return true;
	}else{
		return false;
	}
}

//--------------------------------------------------------------
bool ofMesh::haveNormalsChanged(){
	if(bNormalsChanged){
		bNormalsChanged = false;
		return true;
	}else{
		return false;
	}
}

//--------------------------------------------------------------
bool ofMesh::haveTexCoordsChanged(){
	if(bTexCoordsChanged){
		bTexCoordsChanged = false;
		return true;
	}else{
		return false;
	}
}

//--------------------------------------------------------------
bool ofMesh::haveIndicesChanged(){
	if(bIndicesChanged){
		bIndicesChanged = false;
		return true;
	}else{
		return false;
	}
}


//--------------------------------------------------------------
bool ofMesh::hasVertices() const{
	return !vertices.empty();
}

//--------------------------------------------------------------
bool ofMesh::hasColors() const{
	return !colors.empty();
}

//--------------------------------------------------------------
bool ofMesh::hasNormals() const{
	return !normals.empty();
}

//--------------------------------------------------------------
bool ofMesh::hasTexCoords() const{
	return !texCoords.empty();
}

//--------------------------------------------------------------
bool ofMesh::hasIndices() const{
	return !indices.empty();
}

//ADDERS

//--------------------------------------------------------------
void ofMesh::addVertex(const ofVec3f& v){
	vertices.push_back(v);
	bVertsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addVertices(const vector<ofVec3f>& verts){
	vertices.insert(vertices.end(),verts.begin(),verts.end());
	bVertsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addVertices(const ofVec3f* verts, std::size_t amt){
	vertices.insert(vertices.end(),verts,verts+amt);
	bVertsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addColor(const ofFloatColor& c){
	colors.push_back(c);
	bColorsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addColors(const vector<ofFloatColor>& cols){
	colors.insert(colors.end(),cols.begin(),cols.end());
	bColorsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addColors(const ofFloatColor* cols, std::size_t amt){
	colors.insert(colors.end(),cols,cols+amt);
	bColorsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addNormal(const ofVec3f& n){
	normals.push_back(n);
	bNormalsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addNormals(const vector<ofVec3f>& norms){
	normals.insert(normals.end(),norms.begin(),norms.end());
	bNormalsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addNormals(const ofVec3f* norms, std::size_t amt){
	normals.insert(normals.end(),norms,norms+amt);
	bNormalsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addTexCoord(const ofVec2f& t){
	//TODO: figure out if we add to all other arrays to match
	texCoords.push_back(t);
	bTexCoordsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addTexCoords(const vector<ofVec2f>& tCoords){
	texCoords.insert(texCoords.end(),tCoords.begin(),tCoords.end());
	bTexCoordsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addTexCoords(const ofVec2f* tCoords, std::size_t amt){
	texCoords.insert(texCoords.end(),tCoords,tCoords+amt);
	bTexCoordsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
ofIndexType ofMesh::getIndex(ofIndexType i) const{
	return indices[i];
}

//--------------------------------------------------------------
void ofMesh::addIndex(ofIndexType i){
	indices.push_back(i);
	bIndicesChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addIndices(const vector<ofIndexType>& inds){
	indices.insert(indices.end(),inds.begin(),inds.end());
	bIndicesChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addIndices(const ofIndexType* inds, std::size_t amt){
	indices.insert(indices.end(),inds,inds+amt);
	bIndicesChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::addTriangle(ofIndexType index1, ofIndexType index2, ofIndexType index3) {
	addIndex(index1);
	addIndex(index2);
	addIndex(index3);
}

//REMOVERS
//--------------------------------------------------------------
void ofMesh::removeVertex(ofIndexType index){
  if(index >= vertices.size()){
	ofLogError("ofMesh") << "removeVertex(): ignoring out of range index " << index << ", number of vertices is" << vertices.size();
  }else{
	vertices.erase(vertices.begin() + index);
	bVertsChanged = true;
	bFacesDirty = true;
  }
}

//--------------------------------------------------------------
void ofMesh::removeNormal(ofIndexType index){
  if(index >= normals.size()){
	ofLogError("ofMesh") << "removeNormal(): ignoring out of range index " << index << ", number of normals is" << normals.size();
  }else{
	normals.erase(normals.begin() + index);
	bNormalsChanged = true;
	bFacesDirty = true;
  }
}

//--------------------------------------------------------------
void ofMesh::removeColor(ofIndexType index){
  if(index >= colors.size()){
	ofLogError("ofMesh") << "removeColor(): ignoring out of range index " << index << ", number of colors is" << colors.size();
  }else{
	colors.erase(colors.begin() + index);
	bColorsChanged = true;
	bFacesDirty = true;
  }
}

//--------------------------------------------------------------
void ofMesh::removeTexCoord(ofIndexType index){
  if(index >= texCoords.size()){
	ofLogError("ofMesh") << "removeTexCoord(): ignoring out of range index " << index << ", number of tex coords is" << texCoords.size();
  }else{
	texCoords.erase(texCoords.begin() + index);
	bTexCoordsChanged = true;
	bFacesDirty = true;
  }
}

//--------------------------------------------------------------
void ofMesh::removeIndex(ofIndexType index){
  if(index >= indices.size()){
	ofLogError("ofMesh") << "removeIndex(): ignoring out of range index " << index << ", number of indices is" << indices.size();
  }else{
	indices.erase(indices.begin() + index);
	bIndicesChanged = true;
	bFacesDirty = true;
  }
}


//GETTERS
//--------------------------------------------------------------
ofPrimitiveMode ofMesh::getMode() const{
	return mode;
}

//--------------------------------------------------------------
ofVec3f ofMesh::getVertex(ofIndexType i) const{
	return vertices[i];
}

//--------------------------------------------------------------
ofVec3f ofMesh::getNormal(ofIndexType i) const{
	return normals[i];
}

//--------------------------------------------------------------
ofFloatColor ofMesh::getColor(ofIndexType i) const{
	return colors[i];
}

//--------------------------------------------------------------
ofVec2f ofMesh::getTexCoord(ofIndexType i) const{
	return texCoords[i];
}

//--------------------------------------------------------------
std::size_t ofMesh::getNumVertices() const{
	return vertices.size();
}

//--------------------------------------------------------------
std::size_t ofMesh::getNumColors() const{
	return colors.size();
}

//--------------------------------------------------------------
std::size_t ofMesh::getNumNormals() const{
	return normals.size();
}

//--------------------------------------------------------------
std::size_t ofMesh::getNumTexCoords() const{
	return texCoords.size();
}

//--------------------------------------------------------------
std::size_t ofMesh::getNumIndices() const{
	return indices.size();
}

/*
//--------------------------------------------------------------
int ofPrimitive::getNumIndicesSolid(){
	return indicesSolid.size();
}

//--------------------------------------------------------------
int ofPrimitive::getNumIndicesWire(){
	return indicesWire.size();
}
 */

//--------------------------------------------------------------
ofVec3f* ofMesh::getVerticesPointer(){
#ifdef TARGET_OSX
	return &vertices[0];
#else
	return vertices.data();
#endif
}

//--------------------------------------------------------------
ofFloatColor* ofMesh::getColorsPointer(){
#ifdef TARGET_OSX
	return &colors[0];
#else
	return colors.data();
#endif
}

//--------------------------------------------------------------
ofVec3f* ofMesh::getNormalsPointer(){
#ifdef TARGET_OSX
		return &normals[0];
#else
	return normals.data();
#endif
}

//--------------------------------------------------------------
ofVec2f* ofMesh::getTexCoordsPointer(){
#ifdef TARGET_OSX
		return &texCoords[0];
#else
	return texCoords.data();
#endif
}

//--------------------------------------------------------------
ofIndexType* ofMesh::getIndexPointer(){
#ifdef TARGET_OSX
		return &indices[0];
#else
	return indices.data();
#endif
}


//--------------------------------------------------------------
const ofVec3f* ofMesh::getVerticesPointer() const{
#ifdef TARGET_OSX
	return &vertices[0];
#else
	return vertices.data();
#endif
}

//--------------------------------------------------------------
const ofFloatColor* ofMesh::getColorsPointer() const{
#ifdef TARGET_OSX
	return &colors[0];
#else
	return colors.data();
#endif
}

//--------------------------------------------------------------
const ofVec3f* ofMesh::getNormalsPointer() const{
#ifdef TARGET_OSX
	return &normals[0];
#else
	return normals.data();
#endif
}

//--------------------------------------------------------------
const ofVec2f* ofMesh::getTexCoordsPointer() const{
#ifdef TARGET_OSX
	return &texCoords[0];
#else
	return texCoords.data();
#endif
}

//--------------------------------------------------------------
const ofIndexType * ofMesh::getIndexPointer() const{
#ifdef TARGET_OSX
	return &indices[0];
#else
	return indices.data();
#endif
}

vector<ofVec3f> & ofMesh::getVertices(){
	bVertsChanged = true;
	bFacesDirty = true;
	return vertices;
}

vector<ofFloatColor> & ofMesh::getColors(){
	bColorsChanged = true;
	bFacesDirty = true;
	return colors;
}

vector<ofVec3f> & ofMesh::getNormals(){
	bNormalsChanged = true;
	bFacesDirty = true;
	return normals;
}

vector<ofVec2f> & ofMesh::getTexCoords(){
	bTexCoordsChanged = true;
	bFacesDirty = true;
	return texCoords;
}

vector<ofIndexType> & ofMesh::getIndices(){
	bIndicesChanged = true;
	bFacesDirty = true;
	return indices;
}

const vector<ofVec3f> & ofMesh::getVertices() const{
	return vertices;
}

const vector<ofFloatColor> & ofMesh::getColors() const{
	return colors;
}

const vector<ofVec3f> & ofMesh::getNormals() const{
	return normals;
}

const vector<ofVec2f> & ofMesh::getTexCoords() const{
	return texCoords;
}

const vector<ofIndexType> & ofMesh::getIndices() const{
	return indices;
}

/*
//--------------------------------------------------------------
GLuint* ofPrimitive::getSolidIndexPointer(){
	return &indicesSolid[0];
}

//--------------------------------------------------------------
GLuint* ofPrimitive::getWireIndexPointer(){
	return &indicesWire[0];
}
 */

/*
//--------------------------------------------------------------
vector<int>& ofPrimitive::getFace(int faceNum){
	switch(mode){
		//GL_QUADS
		indices[faceNum*4+0];
		indices[faceNum*4+1];
		indices[faceNum*4+2];
		indices[faceNum*4+3];

		//GL_TRIANGLES
		indices[faceNum*3+0];
		indices[faceNum*3+1];
		indices[faceNum*3+2];

		//GL_TRIANGLE_FAN
		// 1 element per fan
		indices[0];
		indices[faceNum+1];
		indices[faceNum+2];

		//GL_TRIANGLE_STRIP
		// 1 element per strip
		indices[faceNum+0];
		indices[faceNum+1];
		indices[faceNum+2];
		default:break;
	}
}
 */


//--------------------------------------------------------------
ofVec3f ofMesh::getCentroid() const {
	if(vertices.size() == 0) {
		ofLogWarning("ofMesh") << "getCentroid(): mesh has no vertices, returning ofPoint(0, 0, 0)";
		return ofPoint(0, 0, 0);
	}

	ofVec3f sum;
	for(ofIndexType i = 0; i < vertices.size(); i++) {
		sum += vertices[i];
	}
	sum /= vertices.size();
	return sum;
}

//SETTERS
//--------------------------------------------------------------
void ofMesh::setMode(ofPrimitiveMode m){
	bIndicesChanged = true;
	mode = m;
}

//--------------------------------------------------------------
void ofMesh::setVertex(ofIndexType index, const ofVec3f& v){
	vertices[index] = v;
	bVertsChanged = true;
	bIndicesChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::setNormal(ofIndexType index, const ofVec3f& n){
	normals[index] = n;
	bNormalsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::setColor(ofIndexType index, const ofFloatColor& c){
	colors[index] = c;
	bColorsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::setTexCoord(ofIndexType index, const ofVec2f& t){
	texCoords[index] = t;
	bTexCoordsChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::setIndex(ofIndexType index, ofIndexType  val){
	indices[index] = val;
	bIndicesChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::setupIndicesAuto(){
	bIndicesChanged = true;
	bFacesDirty = true;
	indices.resize(vertices.size());
	for(ofIndexType i = 0; i < vertices.size();i++){
		indices[i]=i;
	}
}



//--------------------------------------------------------------
void ofMesh::clearVertices(){
	vertices.clear();
	bVertsChanged=true;
}

//--------------------------------------------------------------
void ofMesh::clearNormals(){
	normals.clear();
	bNormalsChanged=true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::clearColors(){
	colors.clear();
	bColorsChanged=true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::clearTexCoords(){
	texCoords.clear();
	bTexCoordsChanged=true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::clearIndices(){
	indices.clear();
	bIndicesChanged = true;
	bFacesDirty = true;
}

//--------------------------------------------------------------
void ofMesh::drawVertices() const{
	draw(OF_MESH_POINTS);
}

//--------------------------------------------------------------
void ofMesh::drawWireframe() const{
	draw(OF_MESH_WIREFRAME);
}

//--------------------------------------------------------------
void ofMesh::drawFaces() const{
	draw(OF_MESH_FILL);
}

//--------------------------------------------------------------
void ofMesh::draw() const{
	draw(OF_MESH_FILL);
}

//--------------------------------------------------------------
void ofMesh::draw(ofPolyRenderMode renderType) const{
	if(getNumVertices()==0) return;
	ofGetCurrentRenderer()->draw(*this,renderType,useColors,useTextures,useNormals);
}

//--------------------------------------------------------------
void ofMesh::enableColors(){
	useColors = true;
}

//--------------------------------------------------------------
void ofMesh::enableTextures(){
	useTextures = true;
}

//--------------------------------------------------------------
void ofMesh::enableNormals(){
	useNormals = true;
}

//--------------------------------------------------------------
void ofMesh::enableIndices(){
	useIndices = true;
}

//--------------------------------------------------------------
void ofMesh::disableColors(){
	useColors = false;
}

//--------------------------------------------------------------
void ofMesh::disableTextures(){
	useTextures = false;
}

//--------------------------------------------------------------
void ofMesh::disableNormals(){
	useNormals = false;
}

//--------------------------------------------------------------
void ofMesh::disableIndices(){
	useIndices = false;
}

//--------------------------------------------------------------
bool ofMesh::usingColors() const{
	return useColors;
}

//--------------------------------------------------------------
bool ofMesh::usingTextures() const{
	return useTextures;
}

//--------------------------------------------------------------
bool ofMesh::usingNormals() const{
	return useNormals;
}

//--------------------------------------------------------------
bool ofMesh::usingIndices() const{
	return useIndices;
}


//--------------------------------------------------------------
void ofMesh::append(const ofMesh & mesh){
	ofIndexType prevNumVertices = vertices.size();
	if(mesh.getNumVertices()){
		vertices.insert(vertices.end(),mesh.getVertices().begin(),mesh.getVertices().end());
	}
	if(mesh.getNumTexCoords()){
		texCoords.insert(texCoords.end(),mesh.getTexCoords().begin(),mesh.getTexCoords().end());
	}
	if(mesh.getNumColors()){
		colors.insert(colors.end(),mesh.getColors().begin(),mesh.getColors().end());
	}
	if(mesh.getNumNormals()){
		normals.insert(normals.end(),mesh.getNormals().begin(),mesh.getNormals().end());
	}
	if(mesh.getNumIndices()){
		for(ofIndexType i=0;i<mesh.getIndices().size();i++){
			indices.push_back(mesh.getIndex(i)+prevNumVertices);
		}
	}
}


/*
getline replacement for files with \r \r\n or \n line endings
found meshes with all three
*/
static std::istream& safeGetline(std::istream& is, std::string& t)
{
	t.clear();

	std::istream::sentry se(is, true);
	std::streambuf* sb = is.rdbuf();

	for (;;) {
		int c = sb->sbumpc();
		switch (c) {
		case '\n':
			return is;
		case '\r':
			if (sb->sgetc() == '\n')
				sb->sbumpc();
			return is;
		case EOF:
			// Also handle the case when the last line has no line ending
			if (t.empty())
				is.setstate(std::ios::eofbit);
			return is;
		default:
			t += (char)c;
		}
	}
}


//--------------------------------------------------------------
void ofMesh::load(string path) {
	string filetype = path.substr(path.size() - 3);
	filetype = ofToLower(filetype);
	if (filetype == "obj") {
		loadOBJ(path);
	}
	else if (filetype == "stl") {
		loadSTL(path);
	}
	else {
		loadPLY(path);
	}
}

//--------------------------------------------------------------
void ofMesh::loadPLY(string path) {
	ofFile is(path, ofFile::ReadOnly);
	ofMesh& data = *this;

	string error;
	//ofBuffer buffer(is);
	ofMesh backup = data;

	int orderVertices = -1;
	int orderIndices = -1;

	ofIndexType vertexCoordsFound = 0;
	ofIndexType colorCompsFound = 0;
	ofIndexType texCoordsFound = 0;
	ofIndexType normalsCoordsFound = 0;

	ofIndexType currentVertex = 0;
	ofIndexType currentFace = 0;

	bool binary = false;
	bool littleEndian = true;
	bool floatColor = false;

	enum State {
		Header,
		VertexDef,
		FaceDef,
		Vertices,
		Normals,
		Faces
	};

	data.clear();
	State state = Header;

	int lineNum = 0;
	string line;
	safeGetline(is, line);
	lineNum++;
	if (line != "ply") {
		error = "wrong format, expecting 'ply'";
		goto clean;
	}
	safeGetline(is, line);
	lineNum++;
	if (line == "format binary_little_endian 1.0") {
		loadPLYBinary(is, true);
		return;
	}
	else if (line == "format binary_big_endian 1.0") {
		ofLogError("ofMesh") << "big endian binary files not supported" << endl;
		//loadPLYBinary(is, false);
		return;
	}
	else if (line != "format ascii 1.0") {
		error = "wrong format, expecting 'format ascii 1.0'";
		goto clean;
	}


	while (safeGetline(is, line)) {
		lineNum++;
		string lineStr = line;
		if (lineStr.find("comment") == 0 || lineStr.empty()) {
			continue;
		}

		if ((state == Header || state == FaceDef) && lineStr.find("element vertex") == 0) {
			state = VertexDef;
			orderVertices = MAX(orderIndices, 0) + 1;
			data.getVertices().resize(ofToInt(lineStr.substr(15)));
			continue;
		}

		if ((state == Header || state == VertexDef) && lineStr.find("element face") == 0) {
			state = FaceDef;
			orderIndices = MAX(orderVertices, 0) + 1;
			data.getIndices().resize(ofToInt(lineStr.substr(13)) * 3);
			continue;
		}

		if (state == VertexDef && (lineStr.find("property float x") == 0 || lineStr.find("property float y") == 0 || lineStr.find("property float z") == 0)) {
			vertexCoordsFound++;
			continue;
		}

		if (state == VertexDef && (lineStr.find("property float r") == 0 || lineStr.find("property float g") == 0 || lineStr.find("property float b") == 0 || lineStr.find("property float a") == 0)) {
			colorCompsFound++;
			data.getColors().resize(data.getVertices().size());
			floatColor = true;
			continue;
		}

		if (state == VertexDef && (lineStr.find("property uchar red") == 0 || lineStr.find("property uchar green") == 0 || lineStr.find("property uchar blue") == 0 || lineStr.find("property uchar alpha") == 0)) {
			colorCompsFound++;
			data.getColors().resize(data.getVertices().size());
			floatColor = false;
			continue;
		}

		if (state == VertexDef && (lineStr.find("property float u") == 0 || lineStr.find("property float v") == 0)) {
			texCoordsFound++;
			data.getTexCoords().resize(data.getVertices().size());
			continue;
		}

		if (state == VertexDef && (lineStr.find("property float nx") == 0 || lineStr.find("property float ny") == 0 || lineStr.find("property float nz") == 0)) {
			normalsCoordsFound++;
			if (normalsCoordsFound == 3) data.getNormals().resize(data.getVertices().size());
			continue;
		}

		if (state == FaceDef && lineStr.find("property list") != 0 && lineStr != "end_header") {
			error = "wrong face definition";
			goto clean;
		}

		if (lineStr == "end_header") {
			if (data.hasColors() && colorCompsFound != 3 && colorCompsFound != 4) {
				error = "data has color coordiantes but not correct number of components. Found " + ofToString(colorCompsFound) + " expecting 3 or 4";
				goto clean;
			}
			if (data.hasNormals() && normalsCoordsFound != 3) {
				error = "data has normal coordiantes but not correct number of components. Found " + ofToString(normalsCoordsFound) + " expecting 3";
				goto clean;
			}
			if (!data.hasVertices()) {
				ofLogWarning("ofMesh") << "load(): mesh loaded from \"" << path << "\" has no vertices";
			}
			if (orderVertices == -1) orderVertices = 9999;
			if (orderIndices == -1) orderIndices = 9999;

			if (orderVertices < orderIndices) {
				state = Vertices;
			}
			else {
				state = Faces;
			}
			continue;
		}

		if (state == Vertices) {
			if (data.getNumVertices() <= currentVertex) {
				error = "found more vertices: " + ofToString(currentVertex + 1) + " than specified in header: " + ofToString(data.getNumVertices());
				goto clean;
			}
			stringstream sline(lineStr);
			sline >> data.getVertices()[currentVertex].x;
			sline >> data.getVertices()[currentVertex].y;
			if (vertexCoordsFound>2) sline >> data.getVertices()[currentVertex].z;

			if (colorCompsFound>0) {
				if (floatColor) {
					sline >> data.getColors()[currentVertex].r;
					sline >> data.getColors()[currentVertex].g;
					sline >> data.getColors()[currentVertex].b;
					if (colorCompsFound>3) sline >> data.getColors()[currentVertex].a;
				}
				else {
					ofColor c;
					sline >> c.r;
					sline >> c.g;
					sline >> c.b;
					if (colorCompsFound>3) sline >> c.a;
					data.getColors()[currentVertex] = c;
				}
			}

			if (texCoordsFound>0) {
				ofVec2f uv;
				sline >> uv.x;
				sline >> uv.y;
				data.getTexCoords()[currentVertex] = uv;
			}

			if (normalsCoordsFound>0) {
				ofVec3f n;
				sline >> n.x;
				sline >> n.y;
				sline >> n.z;
				data.getNormals()[currentVertex] = n;
			}

			currentVertex++;
			if (currentVertex == data.getNumVertices()) {
				if (orderVertices<orderIndices) {
					state = Faces;
				}
				else {
					state = Vertices;
				}
			}
			continue;
		}

		if (state == Faces) {
			if (data.getNumIndices() / 3<currentFace) {
				error = "found more faces than specified in header";
				goto clean;
			}
			stringstream sline(lineStr);
			int numV;
			sline >> numV;
			if (numV != 3) {
				error = "face not a triangle";
				goto clean;
			}
			int i;
			sline >> i;
			data.getIndices()[currentFace * 3] = i;
			sline >> i;
			data.getIndices()[currentFace * 3 + 1] = i;
			sline >> i;
			data.getIndices()[currentFace * 3 + 2] = i;

			currentFace++;
			if (currentFace == data.getNumIndices() / 3) {
				if (orderVertices<orderIndices) {
					state = Vertices;
				}
				else {
					state = Faces;
				}
			}
			continue;
		}
	}


	return;
clean:
	ofLogError("ofMesh") << "load(): " << lineNum << ":" << error;
	ofLogError("ofMesh") << "load(): \"" << line << "\"";
	data = backup;
}

//DOES NOT ACCOUNT FOR ENDIANESS
static unsigned int bytesToInt(char b0, char b1, char b2, char b3) {
	char byte_array[] = { b0, b1, b2, b3 };
	unsigned int result;
	std::copy(reinterpret_cast<const char*>(&byte_array[0]),
		reinterpret_cast<const char*>(&byte_array[4]),
		reinterpret_cast<char*>(&result));
	return result;
}

static float bytesToFloat(char b0, char b1, char b2, char b3) {
	char byte_array[] = { b0, b1, b2, b3 };
	float result;
	std::copy(reinterpret_cast<const char*>(&byte_array[0]),
		reinterpret_cast<const char*>(&byte_array[4]),
		reinterpret_cast<char*>(&result));
	return result;
}

/*
Read binary values from an ofFile for loading binary PLY files
does not account for endianness
assumes short = 2 bytes, int = 4 bytes, float = 4 bytes, double = 8 bytes
*/
template<typename T>
void ofMesh::readPLYProperty(ofFile & is, PropertyType type, T & out) {
	if (type == UCHAR) {
		unsigned char v;
		is.read(reinterpret_cast<char*>(&v), sizeof(unsigned char));
		out = v;
	}
	else if (type == CHAR) {
		char v;
		is.read(&v, sizeof(char));
		out = v;
	}
	else if (type == USHORT) {
		unsigned short v;
		is.read(reinterpret_cast<char*>(&v), sizeof(unsigned short));
		out = v;
	}
	else if (type == SHORT) {
		short v;
		is.read(reinterpret_cast<char*>(&v), sizeof(short));
		out = v;
	}
	else if (type == UINT) {
		unsigned int v;
		is.read(reinterpret_cast<char*>(&v), sizeof(unsigned int));
		out = v;
	}
	else if (type == INT) {
		int v;
		is.read(reinterpret_cast<char*>(&v), sizeof(int));
		out = v;
	}
	else if (type == FLOAT) {
		float v;
		is.read(reinterpret_cast<char*>(&v), sizeof(float));
		out = v;
	}
	else if (type == DOUBLE) {
		double v;
		is.read(reinterpret_cast<char*>(&v), sizeof(double));
		out = v;
	}
	else {
		ofLogError("ofMesh") << "Unsupported property type";
	}
}

template<typename T>
void ofMesh::readPLYListProperty(ofFile & is, PropertyType type, T & out) {
	unsigned int listLen;
	readPLYProperty(is, UCHAR, listLen);
	for (int i = 0; i < listLen; ++i) {
		readPLYProperty(is, type, out[i]);
	}
}

void ofMesh::loadPLYBinary(ofFile & is, bool littleEndian) {
	ofMesh& data = *this;

	string error;
	ofMesh backup = data;

	int orderVertices = -1;
	int orderIndices = -1;

	vector<tuple<string, PropertyType, bool> > faceProperties;
	vector<tuple<string, PropertyType, bool> > vertexProperties;

	ofIndexType vertexCoordsFound = 0;
	ofIndexType colorCompsFound = 0;
	ofIndexType texCoordsFound = 0;
	ofIndexType normalsCoordsFound = 0;

	ofIndexType currentVertex = 0;
	ofIndexType currentFace = 0;

	bool floatColor = false;

	enum State {
		Header,
		VertexDef,
		FaceDef,
		Vertices,
		Normals,
		Faces
	};

	data.clear();
	State state = Header;

	unsigned int lineNum = 0;
	ofIndexType numVertices = 0;
	ofIndexType numFaces = 0;

	string lineStr;

	//skip first two lines, already confirmed binary ply type
	lineNum += 2;

	//het header
	while (safeGetline(is, lineStr)) {
		lineNum++;
		if (lineStr.find("comment") == 0 || lineStr.empty()) {
			continue;
		}

		if ((state == Header || state == FaceDef) && lineStr.find("element vertex") == 0) {
			state = VertexDef;
			orderVertices = MAX(orderIndices, 0) + 1;
			numVertices = ofToInt(lineStr.substr(15));
			data.getVertices().resize(numVertices);
		}
		else if ((state == Header || state == VertexDef) && lineStr.find("element face") == 0) {
			state = FaceDef;
			orderIndices = MAX(orderVertices, 0) + 1;
			numFaces = ofToInt(lineStr.substr(13));
			data.getIndices().reserve(numFaces * 3);
		}
		else if (state == VertexDef && (lineStr.find("property float x") == 0 || lineStr.find("property float y") == 0 || lineStr.find("property float z") == 0)) {
			vertexCoordsFound++;
		}
		else if (state == VertexDef && (lineStr.find("property float r") == 0 || lineStr.find("property float g") == 0 || lineStr.find("property float b") == 0 || lineStr.find("property float a") == 0)) {
			colorCompsFound++;
			data.getColors().resize(numVertices);
			floatColor = true;
		}
		else if (state == VertexDef && (lineStr.find("property uchar red") == 0 || lineStr.find("property uchar green") == 0 || lineStr.find("property uchar blue") == 0 || lineStr.find("property uchar alpha") == 0)) {
			colorCompsFound++;
			data.getColors().resize(numVertices);
			floatColor = false;
		}
		else if (state == VertexDef && (lineStr.find("property float u") == 0 || lineStr.find("property float v") == 0)) {
			texCoordsFound++;
			data.getTexCoords().resize(numVertices);
		}
		else if (state == VertexDef && (lineStr.find("property float nx") == 0 || lineStr.find("property float ny") == 0 || lineStr.find("property float nz") == 0)) {
			normalsCoordsFound++;
			if (normalsCoordsFound == 3) data.getNormals().resize(numVertices);
		}
		else if (lineStr == "end_header") {
			if (data.hasColors() && colorCompsFound != 3 && colorCompsFound != 4) {
				ofLogError("ofMesh") << "data has color coordiantes but not correct number of components. Found " + ofToString(colorCompsFound) + " expecting 3 or 4";
				return;
			}
			if (data.hasNormals() && normalsCoordsFound != 3) {
				ofLogError("ofMesh") << "data has normal coordiantes but not correct number of components. Found " + ofToString(normalsCoordsFound) + " expecting 3";
				return;
			}
			if (!data.hasVertices()) {
				ofLogWarning("ofMesh") << "load(): mesh has no vertices";
			}
			if (orderVertices == -1) orderVertices = 9999;
			if (orderIndices == -1) orderIndices = 9999;

			if (orderVertices < orderIndices) {
				state = Vertices;
			}
			else {
				state = Faces;
			}
			break;
		}

		stringstream sline(lineStr);
		string propertyStr, propertyName, token;
		sline >> propertyStr;
		sline >> propertyStr;

		bool isList = false;
		if (propertyStr == "list") {
			sline >> token;
			if (!(token == "uchar" || token == "uint8")) {
				ofLogError("ofMesh") << "load(): line " << lineNum << ": only uchar supported for list property count - " << lineStr;
				return;
			}
			sline >> propertyStr;
			sline >> propertyName;
			isList = true;
		}
		else {
			sline >> propertyName;
		}
		if (propertyStr == "uchar" || propertyStr == "uint8") {
			if (state == FaceDef) faceProperties.push_back(make_tuple(propertyName, UCHAR, isList));
			else if (state == VertexDef) vertexProperties.push_back(make_tuple(propertyName, UCHAR, isList));
		}
		else if (propertyStr == "char" || propertyStr == "int8") {
			if (state == FaceDef) faceProperties.push_back(make_tuple(propertyName, CHAR, isList));
			else if (state == VertexDef) vertexProperties.push_back(make_tuple(propertyName, CHAR, isList));
		}
		else if (propertyStr == "ushort" || propertyStr == "uint16") {
			if (state == FaceDef) faceProperties.push_back(make_tuple(propertyName, USHORT, isList));
			else if (state == VertexDef) vertexProperties.push_back(make_tuple(propertyName, USHORT, isList));
		}
		else if (propertyStr == "short" || propertyStr == "int16") {
			if (state == FaceDef) faceProperties.push_back(make_tuple(propertyName, SHORT, isList));
			else if (state == VertexDef) vertexProperties.push_back(make_tuple(propertyName, SHORT, isList));
		}
		else if (propertyStr == "uint" || propertyStr == "uint32") {
			if (state == FaceDef) faceProperties.push_back(make_tuple(propertyName, UINT, isList));
			else if (state == VertexDef) vertexProperties.push_back(make_tuple(propertyName, UINT, isList));
		}
		else if (propertyStr == "int" || propertyStr == "int32") {
			if (state == FaceDef) faceProperties.push_back(make_tuple(propertyName, INT, isList));
			else if (state == VertexDef) vertexProperties.push_back(make_tuple(propertyName, INT, isList));
		}
		else if (propertyStr == "float" || propertyStr == "float32") {
			if (state == FaceDef) faceProperties.push_back(make_tuple(propertyName, FLOAT, isList));
			else if (state == VertexDef) vertexProperties.push_back(make_tuple(propertyName, FLOAT, isList));
		}
		else if (propertyStr == "double" || propertyStr == "float64") {
			if (state == FaceDef) faceProperties.push_back(make_tuple(propertyName, DOUBLE, isList));
			else if (state == VertexDef) vertexProperties.push_back(make_tuple(propertyName, DOUBLE, isList));
		}
	}

	ofVec3f vertex, normal;
	ofVec2f texCoord;
	ofFloatColor c;

	//this is a hack
	float floatProp, dummy[10];
	ofIndexType indices[6];
	int numFaceIndices;
	string propName;
	PropertyType propType;
	bool isList;
	while (currentFace < numFaces || currentVertex < numVertices) {
		if (state == Vertices) {
			//read properties
			//check to make sure none of these are lists
			for (auto & prop : vertexProperties) {
				tie(propName, propType, isList) = prop;
				if (propName == "x") {
					readPLYProperty(is, propType, vertex.x);
				}
				else if (propName == "y") {
					readPLYProperty(is, propType, vertex.y);
				}
				else if (propName == "z") {
					readPLYProperty(is, propType, vertex.z);
				}
				else if (propName == "nx") {
					readPLYProperty(is, propType, normal.x);
				}
				else if (propName == "ny") {
					readPLYProperty(is, propType, normal.y);
				}
				else if (propName == "nz") {
					readPLYProperty(is, propType, normal.z);
				}
				else if (propName == "u") {
					readPLYProperty(is, propType, texCoord.x);
				}
				else if (propName == "v") {
					readPLYProperty(is, propType, texCoord.y);
				}
				else if (propName == "r" || propName == "red") {
					readPLYProperty(is, propType, c.r);
					if (propType != FLOAT) c.r /= 255;
				}
				else if (propName == "g" || propName == "green") {
					readPLYProperty(is, propType, c.g);
					if (propType != FLOAT) c.g /= 255;
				}
				else if (propName == "b" || propName == "blue") {
					readPLYProperty(is, propType, c.b);
					if (propType != FLOAT) c.b /= 255;
				}
				else if (propName == "a" || propName == "alpha") {
					readPLYProperty(is, propType, c.a);
					if (propType != FLOAT) c.a /= 255;
				}
				else if (isList) {
					readPLYListProperty(is, propType, dummy);
				}
				else {
					readPLYProperty(is, propType, floatProp);
				}
			}
			data.setVertex(currentVertex, vertex);
			if (normalsCoordsFound > 0) data.setNormal(currentVertex, normal);
			if (colorCompsFound > 0) data.setColor(currentVertex, c);
			if (texCoordsFound > 0) data.setTexCoord(currentVertex, texCoord);

			currentVertex++;
			if (currentVertex == numVertices) state = Faces;
		}
		else if (state == Faces) {
			for (auto & prop : faceProperties) {
				tie(propName, propType, isList) = prop;
				//assume vertex indices are a list of int
				if ((propName == "vertex_index" || propName == "vertex_indices")) {
					readPLYProperty(is, UCHAR, numFaceIndices);
					if (numFaceIndices != 3) {
						ofLogError("ofMesh") << "load(): only 3 sided faces supported";
						return;
					}
					for (int i = 0; i < numFaceIndices; ++i) {
						readPLYProperty(is, propType, indices[i]);
					}
				}
				else if (isList) {
					readPLYListProperty(is, propType, dummy);
				}
				else {
					readPLYProperty(is, propType, floatProp);
				}
				data.addIndices(indices, numFaceIndices);
				currentFace++;
			}
			if (currentFace == numFaces) state = Vertices;
		}
	}
}

//--------------------------------------------------------------
/*
load STL file
does not support ascii files
does not support color
*/
void ofMesh::loadSTL(string path) {
	ofFile is(path, ofFile::ReadOnly);
	ofMesh& data = *this;


	string error;
	ofBuffer buffer(is);
	ofMesh backup = data;

	bool floatColor = false;


	data.clear();

	char * stlData = buffer.getData();

	string line = buffer.getFirstLine();
	int index = 0;


	if (line.substr(0, 5) == "solid") {
		error = "wrong format, expecting 'binary'";
		goto clean;
	}

	//skip header
	stlData = stlData + 80;

	unsigned int numTri = bytesToInt(*(stlData), *(stlData + 1), *(stlData + 2), *(stlData + 3));
	stlData += 4;
	ofLogError("ofMesh") << "number of triangles " << numTri;
	try {
		for (int i = 0; i < numTri; ++i) {
			//skip normal
			stlData += 12;
			ofVec3f v(bytesToFloat(*(stlData), *(stlData + 1), *(stlData + 2), *(stlData + 3)), bytesToFloat(*(stlData + 4), *(stlData + 5), *(stlData + 6), *(stlData + 7)), bytesToFloat(*(stlData + 8), *(stlData + 9), *(stlData + 10), *(stlData + 11)));
			stlData += 12;
			data.addVertex(v);
			v.set(bytesToFloat(*(stlData), *(stlData + 1), *(stlData + 2), *(stlData + 3)), bytesToFloat(*(stlData + 4), *(stlData + 5), *(stlData + 6), *(stlData + 7)), bytesToFloat(*(stlData + 8), *(stlData + 9), *(stlData + 10), *(stlData + 11)));
			stlData += 12;
			data.addVertex(v);
			v.set(bytesToFloat(*(stlData), *(stlData + 1), *(stlData + 2), *(stlData + 3)), bytesToFloat(*(stlData + 4), *(stlData + 5), *(stlData + 6), *(stlData + 7)), bytesToFloat(*(stlData + 8), *(stlData + 9), *(stlData + 10), *(stlData + 11)));
			stlData += 12;
			data.addVertex(v);

			//skip attribute
			stlData += 2;

			data.addIndex(index++);
			data.addIndex(index++);
			data.addIndex(index++);
		}
	}
	catch (exception e) {
		error = "wrong number of triangles";
		goto clean;
	}


	return;
clean:
	ofLogError("ofMesh") << "load(): " << error;
	data = backup;
}

//--------------------------------------------------------------
void ofMesh::loadOBJ(string path) {
	ofFile is(path, ofFile::ReadOnly);
	ofMesh& data = *this;


	string error;
	ofBuffer buffer(is);
	ofMesh backup = data;

	int orderVertices = -1;
	int orderIndices = -1;

	ofIndexType vertexCoordsFound = 0;
	ofIndexType colorCompsFound = 0;
	ofIndexType texCoordsFound = 0;
	ofIndexType normalsCoordsFound = 0;

	ofIndexType currentVertex = 0;
	ofIndexType currentFace = 0;

	bool floatColor = false;

	enum State {
		Header,
		VertexDef,
		FaceDef,
		Vertices,
		Normals,
		Faces
	};

	data.clear();
	State state = Header;

	int lineNum = 0;
	ofBuffer::Lines lines = buffer.getLines();
	ofBuffer::Line line = lines.begin();

	ofFloatColor col;
	col.a = 1.0;
	//currently ignoring object tags
	//ignoring colors and textures for now
	ofVec3f v;
	string token;
	for (; line != lines.end(); ++line) {
		lineNum++;
		string lineStr = *line;
		if (lineStr.empty() || lineStr.at(0) == '#') {
			continue;
		}
		stringstream sline(lineStr);
		sline >> token;
		if (token == "v") {
			sline >> v.x;
			sline >> v.y;
			sline >> v.z;
			data.addVertex(v);
			if (!sline.eof()) {
				sline >> col.r;
				sline >> col.g;
				sline >> col.b;
				if (!sline.eof()) {
					sline >> col.a;
				}
				data.addColor(col);
			}
		}
		else if (token == "f") {
			//faces with more than 3 vertices not supported
			unsigned int index;
			unsigned int numVert = 0;
			while (!sline.eof()) {
				if (numVert == 3) {
					ofLogError("ofMesh") << "load(): " << lineNum << ": more than 3 vertices in a face not supported";
					return;
				}
				sline >> token;
				index = stoi(token);
				data.addIndex(index - 1);
				numVert++;
			}
			//while (getline(sline, token, ' ')) {

			//}
		}
		else if (token == "vn") {
			data.enableNormals();
			sline >> v.x;
			sline >> v.y;
			sline >> v.z;
			data.addNormal(v);
		}
		else if (token == "vt") {
			data.enableNormals();
			sline >> v.x;
			sline >> v.y;
			data.addTexCoord(v);
		}
	}
	return;
}


void ofMesh::save(string path, bool useBinary) const {
	string filetype = path.substr(path.size() - 4);
	filetype = ofToLower(filetype);
	if (filetype == ".stl") {
		saveSTL(path);
	}
	else if (filetype == ".obj") {
		saveOBJ(path);
	}
	else {
		savePLY(path, useBinary);
	}
}

void ofMesh::savePLY(string path, bool useBinary) const {
	ofFile os(path, ofFile::WriteOnly);
	const ofMesh& data = *this;

	os << "ply" << endl;
	if (useBinary) {
		os << "format binary_little_endian 1.0" << endl;
	}
	else {
		os << "format ascii 1.0" << endl;
	}

	if (data.getNumVertices()) {
		os << "element vertex " << data.getNumVertices() << endl;
		os << "property float x" << endl;
		os << "property float y" << endl;
		os << "property float z" << endl;
		if (data.getNumColors()) {
			os << "property uchar red" << endl;
			os << "property uchar green" << endl;
			os << "property uchar blue" << endl;
			os << "property uchar alpha" << endl;
		}
		if (data.getNumTexCoords()) {
			os << "property float u" << endl;
			os << "property float v" << endl;
		}
		if (data.getNumNormals()) {
			os << "property float nx" << endl;
			os << "property float ny" << endl;
			os << "property float nz" << endl;
		}
	}

	std::size_t faceSize = 3;
	if (data.getNumIndices()) {
		os << "element face " << data.getNumIndices() / faceSize << endl;
		os << "property list uchar int vertex_indices" << endl;
	}
	else if (data.getMode() == OF_PRIMITIVE_TRIANGLES) {
		os << "element face " << data.getNumVertices() / faceSize << endl;
		os << "property list uchar int vertex_indices" << endl;
	}

	os << "end_header" << endl;

	for (std::size_t i = 0; i < data.getNumVertices(); i++) {
		if (useBinary) {
			os.write((char*)&data.getVertices()[i], sizeof(ofVec3f));
		}
		else {
			os << data.getVertex(i).x << " " << data.getVertex(i).y << " " << data.getVertex(i).z;
		}
		if (data.getNumColors()) {
			// VCG lib / MeshLab don't support float colors, so we have to cast
			ofColor cur = data.getColors()[i];
			if (useBinary) {
				os.write((char*)&cur, sizeof(ofColor));
			}
			else {
				os << " " << (int)cur.r << " " << (int)cur.g << " " << (int)cur.b << " " << (int)cur.a;
			}
		}
		if (data.getNumTexCoords()) {
			if (useBinary) {
				os.write((char*)&data.getTexCoords()[i], sizeof(ofVec2f));
			}
			else {
				os << " " << data.getTexCoord(i).x << " " << data.getTexCoord(i).y;
			}
		}
		if (data.getNumNormals()) {
			if (useBinary) {
				os.write((char*)&data.getNormals()[i], sizeof(ofVec3f));
			}
			else {
				os << " " << data.getNormal(i).x << " " << data.getNormal(i).y << " " << data.getNormal(i).z;
			}
		}
		if (!useBinary) {
			os << endl;
		}
	}

	if (data.getNumIndices()) {
		for (std::size_t i = 0; i < data.getNumIndices(); i += faceSize) {
			if (useBinary) {
				os.write((char*)&faceSize, sizeof(unsigned char));
				for (std::size_t j = 0; j < faceSize; j++) {
					int curIndex = data.getIndex(i + j);
					os.write((char*)&curIndex, sizeof(int));
				}
			}
			else {
				os << (std::size_t) faceSize << " " << data.getIndex(i) << " " << data.getIndex(i + 1) << " " << data.getIndex(i + 2) << endl;
			}
		}
	}
	else if (data.getMode() == OF_PRIMITIVE_TRIANGLES) {
		for (std::size_t i = 0; i < data.getNumVertices(); i += faceSize) {
			std::size_t indices[] = { i, i + 1, i + 2 };
			if (useBinary) {
				os.write((char*)&faceSize, sizeof(unsigned char));
				for (std::size_t j = 0; j < faceSize; j++) {
					os.write((char*)&indices[j], sizeof(std::size_t));
				}
			}
			else {
				os << (std::size_t) faceSize << " " << indices[0] << " " << indices[1] << " " << indices[2] << endl;
			}
		}
	}

	//TODO: add index generation for other OF_PRIMITIVE cases
}

void ofMesh::saveOBJ(string path) const {
	ofFile os(path, ofFile::WriteOnly);
	const ofMesh& data = *this;

	bool doColor = data.getNumColors() > 0;
	for (std::size_t i = 0; i < data.getNumVertices(); i++) {
		ofVec3f &v = data.getVertex(i);
		os << "v " << v.x << " " << v.y << " " << v.z;

		if (doColor) {
			ofColor cur = data.getColor(i);
			os << " " << cur.r / 255.0 << " " << cur.g / 255.0 << " " << cur.b / 255.0;
		}
		os << endl;
	}
	for (std::size_t i = 0; i < data.getNumNormals(); i++) {
		ofVec3f &v = data.getNormal(i);
		os << "vn " << v.x << " " << v.y << " " << v.z << endl;
	}

	for (std::size_t i = 0; i < data.getNumTexCoords(); i++) {
		ofVec2f &v = data.getTexCoord(i);
		os << "vt " << v.x << " " << v.y << endl;
	}

	int faceSize = 3;
	if (data.getNumIndices()) {
		for (std::size_t i = 0; i < data.getNumIndices(); i += faceSize) {

			os << "f " << data.getIndex(i) + 1 << " " << data.getIndex(i + 1) + 1 << " " << data.getIndex(i + 2) + 1 << endl;
		}
	}
	else if (data.getMode() == OF_PRIMITIVE_TRIANGLES) {
		for (std::size_t i = 0; i < data.getNumVertices(); i += faceSize) {
			os << "f " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
		}
	}
	//TODO: add index generation for other OF_PRIMITIVE cases
}

void ofMesh::saveSTL(string path) const {
	ofFile os(path, ofFile::WriteOnly);
	const ofMesh& data = *this;
	//header
	unsigned int numTris;
	//no color support
	os.write("Openframeworks STL by Nervous System http://openframeworks.cc http://nervo.us   ", 80);
	if (data.getNumIndices()) {
		numTris = data.getNumIndices() / 3;
	}
	else {
		numTris = data.getNumVertices() / 3;
	}

	os.write((char *)&numTris, sizeof(unsigned int));
	ofVec3f v;

	//end header
	if (data.getNumIndices()) {
		for (std::size_t i = 0; i < data.getNumIndices(); i += 3) {
			//normal
			os.write((char *)&v, sizeof(ofVec3f));
			v = data.getVertex(data.getIndex(i));
			os.write((char *)&v, sizeof(ofVec3f));
			v = data.getVertex(data.getIndex(i + 1));
			os.write((char *)&v, sizeof(ofVec3f));
			v = data.getVertex(data.getIndex(i + 2));
			os.write((char *)&v, sizeof(ofVec3f));
			//end triangle could be used to encode color
			os.write("  ", 2);
		}
	}
	else if (data.getMode() == OF_PRIMITIVE_TRIANGLES) {
		for (std::size_t i = 0; i < data.getNumVertices(); i += 3) {
			os.write((char *)&v, sizeof(ofVec3f));
			v = data.getVertex(i);
			os.write((char *)&v, sizeof(ofVec3f));
			v = data.getVertex(i + 1);
			os.write((char *)&v, sizeof(ofVec3f));
			v = data.getVertex(i + 2);
			os.write((char *)&v, sizeof(ofVec3f));
			//end triangle could be used to encode color
			os.write("  ", 2);
		}
	}

	//TODO: add index generation for other OF_PRIMITIVE cases
}

//----------------------------------------------------------
void ofMesh::setColorForIndices( ofIndexType startIndex, ofIndexType endIndex, ofColor color ) {
	if(!hasColors()) {
		// no colors for vertices, so we must set them here //
		getColors().resize( getNumVertices() );
	}

	for(ofIndexType i = startIndex; i < endIndex; i++) {
		setColor( getIndex(i), color);
	}
}

//----------------------------------------------------------
ofMesh ofMesh::getMeshForIndices( ofIndexType startIndex, ofIndexType endIndex ) const {
	ofIndexType startVertIndex = 0;
	ofIndexType endVertIndex = 0;

	if(startIndex >= getNumIndices() ) {
		startVertIndex = 0;
	} else {
		startVertIndex = getIndex( startIndex );
	}

	if(endIndex >= getNumIndices() ) {
		// set to the total, because the vector assign does not include the last element //
		endVertIndex = getNumVertices();
	} else {
		endVertIndex = getIndex( endIndex );
	}
	return getMeshForIndices(startIndex, endIndex, startVertIndex, endVertIndex );
}

//----------------------------------------------------------
ofMesh ofMesh::getMeshForIndices( ofIndexType startIndex, ofIndexType endIndex, ofIndexType startVertIndex, ofIndexType endVertIndex ) const{

	ofMesh mesh;
	mesh.setMode( getMode() );

	mesh.getVertices().assign( getVertices().begin()+startVertIndex, getVertices().begin()+endVertIndex );

	if( hasColors() ) {
		vector<ofFloatColor> colors;
		mesh.getColors().assign( getColors().begin()+startVertIndex, getColors().begin()+endVertIndex );
		if( usingColors()) mesh.enableColors();
		else mesh.disableColors();
	}

	if( hasTexCoords() ) {
		mesh.getTexCoords().assign( getTexCoords().begin()+startVertIndex, getTexCoords().begin()+endVertIndex );
		if( usingTextures() ) mesh.enableTextures();
		else mesh.disableTextures();
	}

	if( hasNormals() ) {
		mesh.getNormals().assign( getNormals().begin()+startVertIndex, getNormals().begin()+endVertIndex );
		if( usingNormals() ) mesh.enableNormals();
		else mesh.disableNormals();
	}

	ofIndexType offsetIndex = getIndex(startIndex);
	bool bFoundLessThanZero = false;
	for(ofIndexType i = startIndex; i < endIndex; i++) {
		ofIndexType index;
		if(getIndex(i)<offsetIndex){
			index = 0;
			bFoundLessThanZero = true;
		}else{
			index = getIndex(i) - offsetIndex;
		}
		mesh.addIndex( index );
	}

	if(bFoundLessThanZero) {
		ofLogWarning( "ofMesh :: getMeshForIndices : found some indices less than 0, setting them to 0"  );
	}

	return mesh;
}

//----------------------------------------------------------
void ofMesh::mergeDuplicateVertices() {

	vector<ofVec3f> verts = getVertices();
	vector<ofIndexType> indices = getIndices();

	//get indexes to share single point - TODO: try j < i
	for(ofIndexType i = 0; i < indices.size(); i++) {
		for(ofIndexType j = 0; j < indices.size(); j++ ) {
			if(i==j) continue;

			ofIndexType i1 = indices[i];
			ofIndexType i2 = indices[j];
			ofVec3f v1 = verts[ i1 ];
			ofVec3f v2 = verts[ i2 ];

			if( v1 == v2 && i1 != i2) {
				indices[j] = i1;
				break;
			}
		}
	}

	//indices array now has list of unique points we need
	//but we need to delete the old points we're not using and that means the index values will change
	//so we are going to create a new list of points and new indexes - we will use a map to map old index values to the new ones
	vector <ofPoint> newPoints;
	vector <ofIndexType> newIndexes;
	map <ofIndexType, bool> ptCreated;
	map <ofIndexType, ofIndexType> oldIndexNewIndex;

	vector<ofFloatColor> newColors;
	vector<ofFloatColor>& colors = getColors();
	vector<ofVec2f> newTCoords;
	vector<ofVec2f>& tcoords = getTexCoords();
	vector<ofVec3f> newNormals;
	vector<ofVec3f>& normals = getNormals();

	for(ofIndexType i = 0; i < indices.size(); i++){
		ptCreated[i] = false;
	}

	for(ofIndexType i = 0; i < indices.size(); i++){
		ofIndexType index = indices[i];
		ofPoint p = verts[ index ];

		if( ptCreated[index] == false ){
			oldIndexNewIndex[index] = newPoints.size();
			newPoints.push_back( p );
			if(hasColors()) {
				newColors.push_back(colors[index]);
			}
			if(hasTexCoords()) {
				newTCoords.push_back(tcoords[index]);
			}
			if(hasNormals()) {
				newNormals.push_back(normals[index]);
			}

			ptCreated[index] = true;
		}

		//ofLogNotice("ofMesh") << "[" << i << "]: old " << index << " --> " << oldIndexNewIndex[index];
		newIndexes.push_back( oldIndexNewIndex[index] );
	}

	verts.clear();
	verts = newPoints;

	indices.clear();
	indices = newIndexes;

	clearIndices();
	addIndices(indices);
	clearVertices();
	addVertices( verts );

	if(hasColors()) {
		clearColors();
		addColors( newColors );
	}

	if(hasTexCoords()) {
		clearTexCoords();
		addTexCoords( newTCoords );
	}

	if(hasNormals()) {
		clearNormals();
		addNormals( newNormals );
	}

}

//----------------------------------------------------------
ofMeshFace ofMesh::getFace(ofIndexType faceId) const{
	const vector<ofMeshFace> & faces = getUniqueFaces();
	if(faces.size()>faceId){
		return faces[faceId];
	}else{
		ofLogError() << "couldn't find face " << faceId;
		return ofMeshFace();
	}
}

//----------------------------------------------------------
const vector<ofMeshFace> & ofMesh::getUniqueFaces() const{
	if(bFacesDirty){
		// if we are doing triangles, we have to use a vert and normal for each triangle
		// that way we can calculate face normals and use getFaceNormal();
		faces.resize( indices.size()/3 );

		int index	   = 0;
		int triindex	= 0;

		bool bHasColors	 = hasColors();
		bool bHasNormals	= hasNormals();
		bool bHasTexcoords  = hasTexCoords();

		if( getMode() == OF_PRIMITIVE_TRIANGLES) {
			for(std::size_t j = 0; j < indices.size(); j += 3) {
				ofMeshFace & tri = faces[triindex];
				for(std::size_t k = 0; k < 3; k++) {
					index = indices[j+k];
					tri.setVertex( k, vertices[index] );
					if(bHasNormals)
						tri.setNormal(k, normals[index] );
					if(bHasTexcoords)
						tri.setTexCoord(k, texCoords[index] );
					if(bHasColors)
						tri.setColor(k, colors[index] );
				}
				triindex++;
			}

		} else {
			ofLogWarning("ofMesh") << "getUniqueFaces(): only works with primitive mode OF_PRIMITIVE_TRIANGLES";
		}

		bFacesDirty = false;
	}

	return faces;

}

//----------------------------------------------------------
vector<ofVec3f> ofMesh::getFaceNormals( bool perVertex ) const{
	// default for ofPrimitiveBase is vertex normals //
	vector<ofVec3f> faceNormals;

	if( hasVertices() ) {
		if(vertices.size() > 3 && indices.size() > 3) {
			if(perVertex){
				faceNormals.resize(indices.size()*3);
			}else{
				faceNormals.resize(indices.size());
			}
			ofMeshFace face;
			ofVec3f n;
			for(ofIndexType i = 0; i < indices.size(); i+=3) {
				face.setVertex( 0, vertices[indices[i+0]] );
				face.setVertex( 1, vertices[indices[i+1]] );
				face.setVertex( 2, vertices[indices[i+2]] );

				n = face.getFaceNormal();

				faceNormals[i]=n;
				if(perVertex) {
					faceNormals[i+1]=n;
					faceNormals[i+2]=n;
				}
			}
		}
	}

	return faceNormals;
}

//----------------------------------------------------------
void ofMesh::setFromTriangles( const vector<ofMeshFace>& tris, bool bUseFaceNormal ) {
	if(tris.empty()) {
		ofLogWarning("ofMesh") << "setFromTriangles(): ignoring empty tris vector";
		return;
	}

	vector<ofMeshFace>::const_iterator it;

	vertices.resize(tris.size()*3 );
	it = tris.begin();
	// if the first tri has data, assume the rest do as well //
	if(it->hasNormals()){
		normals.resize(tris.size()*3);
	}else{
		normals.clear();
	}
	if(it->hasColors()){
		colors.resize(tris.size()*3);
	}else{
		colors.clear();
	}
	if(it->hasTexcoords()){
		texCoords.resize(tris.size()*3);
	}else{
		texCoords.clear();
	}

	int i = 0;
	for(it = tris.begin(); it != tris.end(); it++) {
		for(std::size_t k = 0; k < 3; k++) {
			vertices[i] = it->getVertex(k);
			if(it->hasTexcoords())
				texCoords[i] = it->getTexCoord(k);
			if(it->hasColors())
				colors[i] = it->getColor(k);
			if(bUseFaceNormal)
				normals[i] = it->getFaceNormal();
			else if(it->hasNormals())
				normals[i] = it->getNormal(k);
			i++;
		}
	}

	setupIndicesAuto();
	bVertsChanged = true;
	bIndicesChanged = true;
	bNormalsChanged = true;
	bColorsChanged = true;
	bTexCoordsChanged = true;

	bFacesDirty = false;
	faces = tris;
}

//----------------------------------------------------------
void ofMesh::smoothNormals(float angle) {
	enableNormals();
	normals.clear();
	normals.resize(vertices.size(), ofVec3f());

	ofVec3f U, V, p1, p2, p3;
	ofIndexType i1, i2, i3;
	for (int i = 0; i < indices.size();) {
		i1 = indices[i++];
		i2 = indices[i++];
		i3 = indices[i++];
		p1 = vertices[i1];
		p2 = vertices[i2];
		p3 = vertices[i3];

		V = p2 - p1;
		U = p3 - p1;
		U.cross(V);
		normals[i1] += U;
		normals[i2] += U;
		normals[i3] += U;
	}
	for (int i = 0; i < normals.size(); ++i) {
		normals[i].normalize();
		if (angle) {
			normals[i] *= -1;
		}
	}

	bNormalsChanged = true;
}

// PLANE MESH //
//--------------------------------------------------------------
ofMesh ofMesh::plane(float width, float height, int columns, int rows, ofPrimitiveMode mode ) {
	ofMesh mesh;

	if(mode != OF_PRIMITIVE_TRIANGLE_STRIP && mode != OF_PRIMITIVE_TRIANGLES) {
		ofLogWarning("ofMesh") << "ofGetPlaneMesh(): primtive mode " << mode << " not supported, setting to OF_PRIMITIVE_TRIANGLES";
		mode = OF_PRIMITIVE_TRIANGLES;
	}

	mesh.setMode(mode);

	ofVec3f vert;
	ofVec3f normal(0, 0, 1); // always facing forward //
	ofVec2f texcoord;

	// the origin of the plane is the center //
	float halfW = width/2.f;
	float halfH = height/2.f;
	// add the vertexes //
	for(int iy = 0; iy < rows; iy++) {
		for(int ix = 0; ix < columns; ix++) {

			// normalized tex coords //
			texcoord.x = ((float)ix/((float)columns-1.f));
			texcoord.y = ((float)iy/((float)rows-1.f));

			vert.x = texcoord.x * width - halfW;
			vert.y = texcoord.y * height - halfH;

			mesh.addVertex(vert);
			mesh.addTexCoord(texcoord);
			mesh.addNormal(normal);
		}
	}
	if(mode == OF_PRIMITIVE_TRIANGLE_STRIP) {
		for(int y = 0; y < rows-1; y++) {
			// even rows //
			if((y&1)==0) {
				for(int x = 0; x < columns; x++) {
					mesh.addIndex( (y) * columns + x );
					mesh.addIndex( (y+1) * columns + x);
				}
			} else {
				for(int x = columns-1; x >0; x--) {
					mesh.addIndex( (y+1) * columns + x );
					mesh.addIndex( y * columns + x-1 );
				}
			}
		}

		if(rows%2!=0) mesh.addIndex(mesh.getNumVertices()-columns);
	} else {
		// Triangles //
		for(int y = 0; y < rows-1; y++) {
			for(int x = 0; x < columns-1; x++) {
				// first triangle //
				mesh.addIndex((y)*columns + x);
				mesh.addIndex((y)*columns + x+1);
				mesh.addIndex((y+1)*columns + x);

				// second triangle //
				mesh.addIndex((y)*columns + x+1);
				mesh.addIndex((y+1)*columns + x+1);
				mesh.addIndex((y+1)*columns + x);
			}
		}
	}

	return mesh;
}


//----------------------------------------------------------
ofMesh ofMesh::sphere( float radius, int res, ofPrimitiveMode mode ) {

	ofMesh mesh;

	float doubleRes = res*2.f;
	float polarInc = PI/(res); // ringAngle
	float azimInc = TWO_PI/(doubleRes); // segAngle //

	if(mode != OF_PRIMITIVE_TRIANGLE_STRIP && mode != OF_PRIMITIVE_TRIANGLES) {
		mode = OF_PRIMITIVE_TRIANGLE_STRIP;
	}
	mesh.setMode(mode);

	ofVec3f vert;
	ofVec2f tcoord;

	for(float i = 0; i < res+1; i++) {

		float tr = sin( PI-i * polarInc );
		float ny = cos( PI-i * polarInc );

		tcoord.y = i / res;

		for(float j = 0; j <= doubleRes; j++) {

			float nx = tr * sin(j * azimInc);
			float nz = tr * cos(j * azimInc);

			tcoord.x = j / (doubleRes);

			vert.set(nx, ny, nz);
			mesh.addNormal(vert);
			vert *= radius;
			mesh.addVertex(vert);
			mesh.addTexCoord(tcoord);
		}
	}

	int nr = doubleRes+1;
	if(mode == OF_PRIMITIVE_TRIANGLES) {

		int index1, index2, index3;

		for(float iy = 0; iy < res; iy++) {
			for(float ix = 0; ix < doubleRes; ix++) {

				// first tri //
				if(iy > 0) {
					index1 = (iy+0) * (nr) + (ix+0);
					index2 = (iy+0) * (nr) + (ix+1);
					index3 = (iy+1) * (nr) + (ix+0);

					mesh.addIndex(index1);
					mesh.addIndex(index3);
					mesh.addIndex(index2);
				}

				if(iy < res-1 ) {
					// second tri //
					index1 = (iy+0) * (nr) + (ix+1);
					index2 = (iy+1) * (nr) + (ix+1);
					index3 = (iy+1) * (nr) + (ix+0);

					mesh.addIndex(index1);
					mesh.addIndex(index3);
					mesh.addIndex(index2);

				}
			}
		}

	} else {
		for(int y = 0; y < res; y++) {
			for(int x = 0; x <= doubleRes; x++) {
				mesh.addIndex( (y)*nr + x );
				mesh.addIndex( (y+1)*nr + x );
			}
		}
	}


	return mesh;
}

/*
 -----------------------------------------------------------------------------
 This source file is part of ogre-procedural
 
 For the latest info, see http://code.google.com/p/ogre-procedural/
 
 Copyright (c) 2010 Michael Broutin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 -----------------------------------------------------------------------------
 */
// http://code.google.com/p/ogre-procedural/source/browse/library/src/ProceduralIcoSphereGenerator.cpp

// NO texture coords or normals
// use ofGetIcoSphere(radius, 0) // 0 iterations will return Icosahedron //
//----------------------------------------------------------
ofMesh ofMesh::icosahedron(float radius) {
	ofMesh mesh;

	const float sqrt5 = sqrt(5.0f);
	const float phi = (1.0f + sqrt5) * 0.5f;

	/// Step 1 : Generate icosahedron
	float invnorm = 1/sqrt(phi*phi+1);

	mesh.addVertex(invnorm*ofVec3f(-1,  phi, 0));//0
	mesh.addVertex(invnorm*ofVec3f( 1,  phi, 0));//1
	mesh.addVertex(invnorm*ofVec3f(0,   1,  -phi));//2
	mesh.addVertex(invnorm*ofVec3f(0,   1,   phi));//3
	mesh.addVertex(invnorm*ofVec3f(-phi,0,  -1));//4
	mesh.addVertex(invnorm*ofVec3f(-phi,0,   1));//5
	mesh.addVertex(invnorm*ofVec3f( phi,0,  -1));//6
	mesh.addVertex(invnorm*ofVec3f( phi,0,   1));//7
	mesh.addVertex(invnorm*ofVec3f(0,   -1, -phi));//8
	mesh.addVertex(invnorm*ofVec3f(0,   -1,  phi));//9
	mesh.addVertex(invnorm*ofVec3f(-1,  -phi,0));//10
	mesh.addVertex(invnorm*ofVec3f( 1,  -phi,0));//11

	ofIndexType firstFaces[] = {
		0,1,2,
		0,3,1,
		0,4,5,
		1,7,6,
		1,6,2,
		1,3,7,
		0,2,4,
		0,5,3,
		2,6,8,
		2,8,4,
		3,5,9,
		3,9,7,
		11,6,7,
		10,5,4,
		10,4,8,
		10,9,5,
		11,8,6,
		11,7,9,
		10,8,11,
		10,11,9
	};

	for(ofIndexType i = 0; i < mesh.getNumVertices(); i++) {
		mesh.setVertex(i, mesh.getVertex(i) * radius);
	}

	for(ofIndexType i = 0; i < 60; i+=3) {
		mesh.addTriangle(firstFaces[i], firstFaces[i+1], firstFaces[i+2]);
	}

	return mesh;
}



// based on code by Michael Broutin for the ogre-procedural library //
// http://code.google.com/p/ogre-procedural/source/browse/library/src/ProceduralIcoSphereGenerator.cpp
// For the latest info, see http://code.google.com/p/ogre-procedural/ //
//----------------------------------------------------------
ofMesh ofMesh::icosphere(float radius, std::size_t iterations) {

	//ofMesh icosahedron = ofGetIcosahedronMesh( 1.f );
	ofMesh icosahedron = ofMesh::icosahedron( 1.f );
	vector<ofVec3f> vertices = icosahedron.getVertices();
	vector<ofIndexType> faces = icosahedron.getIndices();

	ofIndexType size = faces.size();

	/// Step 2 : tessellate
	for (ofIndexType iteration = 0; iteration < iterations; iteration++)
	{
		size*=4;
		vector<ofIndexType> newFaces;
		newFaces.clear();
		//newFaces.resize(size);
		for (ofIndexType i=0; i<size/12; i++)
		{
			std::size_t i1 = faces[i*3];
			std::size_t i2 = faces[i*3+1];
			std::size_t i3 = faces[i*3+2];
			std::size_t i12 = vertices.size();
			std::size_t i23 = i12+1;
			std::size_t i13 = i12+2;
			ofVec3f v1 = vertices[i1];
			ofVec3f v2 = vertices[i2];
			ofVec3f v3 = vertices[i3];
			//make 1 vertice at the center of each edge and project it onto the sphere
			vertices.push_back((v1+v2).getNormalized());
			vertices.push_back((v2+v3).getNormalized());
			vertices.push_back((v1+v3).getNormalized());
			//now recreate indices
			newFaces.push_back(i1);
			newFaces.push_back(i12);
			newFaces.push_back(i13);
			newFaces.push_back(i2);
			newFaces.push_back(i23);
			newFaces.push_back(i12);
			newFaces.push_back(i3);
			newFaces.push_back(i13);
			newFaces.push_back(i23);
			newFaces.push_back(i12);
			newFaces.push_back(i23);
			newFaces.push_back(i13);
		}
		faces.swap(newFaces);
	}

	/// Step 3 : generate texcoords
	vector<ofVec2f> texCoords;
	for (ofIndexType i=0;i<vertices.size();i++)
	{
		const ofVec3f& vec = vertices[i];
		float u, v;
		float r0 = sqrtf(vec.x*vec.x+vec.z*vec.z);
		float alpha;
		alpha = atan2f(vec.z,vec.x);
		u = alpha/TWO_PI+.5f;
		v = atan2f(vec.y, r0)/PI + .5f;
		// reverse the u coord, so the default is texture mapped left to
		// right on the outside of a sphere //
		texCoords.push_back(ofVec2f(1.0-u,v));
	}

	/// Step 4 : fix texcoords
	// find vertices to split
	std::vector<ofIndexType> indexToSplit;

	for (ofIndexType i=0;i<faces.size()/3;i++)
	{
		ofVec2f& t0 = texCoords[faces[i*3+0]];
		ofVec2f& t1 = texCoords[faces[i*3+1]];
		ofVec2f& t2 = texCoords[faces[i*3+2]];

		if (abs(t2.x-t0.x)>0.5)
		{
			if (t0.x<0.5)
				indexToSplit.push_back(faces[i*3]);
			else
				indexToSplit.push_back(faces[i*3+2]);
		}
		if (abs(t1.x-t0.x)>0.5)
		{
			if (t0.x<0.5)
				indexToSplit.push_back(faces[i*3]);
			else
				indexToSplit.push_back(faces[i*3+1]);
		}
		if (abs(t2.x-t1.x)>0.5)
		{
			if (t1.x<0.5)
				indexToSplit.push_back(faces[i*3+1]);
			else
				indexToSplit.push_back(faces[i*3+2]);
		}
	}

	//split vertices
	for (ofIndexType i=0;i<indexToSplit.size();i++)
	{
		ofIndexType index = indexToSplit[i];
		//duplicate vertex
		ofVec3f v = vertices[index];
		ofVec2f t = texCoords[index] + ofVec2f(1.f, 0.f);
		vertices.push_back(v);
		texCoords.push_back(t);
		ofIndexType newIndex = vertices.size()-1;
		//reassign indices
		for (ofIndexType j=0;j<faces.size();j++)
		{
			if (faces[j]==index)
			{
				ofIndexType index1 = faces[(j+1)%3+(j/3)*3];
				ofIndexType index2 = faces[(j+2)%3+(j/3)*3];
				if ((texCoords[index1].x>0.5) || (texCoords[index2].x>0.5))
				{
					faces[j] = newIndex;
				}
			}
		}
	}

	// tig: flip face(=triangle) winding order, so that we are consistent with all other ofPrimitives.
	// i wish there was a more elegant way to do this, but anything happening before "split vertices"
	// makes things very, very complicated.
	
	for (ofIndexType i = 0; i < faces.size(); i+=3) {
		std::swap(faces[i+1], faces[i+2]);
	}

	ofMesh sphere;

	sphere.addIndices( faces );
	sphere.addNormals( vertices );
	sphere.addTexCoords( texCoords );

	for(ofIndexType i = 0; i < vertices.size(); i++ ) {
		vertices[i] *= radius;
	}
	sphere.addVertices( vertices );

	return  sphere;
}
/*
 -----------------------------------------------------------------------------
 // END OGRE
 -----------------------------------------------------------------------------
 */



// Cylinder Mesh
//----------------------------------------------------------
ofMesh ofMesh::cylinder( float radius, float height, int radiusSegments, int heightSegments, int numCapSegments, bool bCapped, ofPrimitiveMode mode ) {
	ofMesh mesh;
	if(mode != OF_PRIMITIVE_TRIANGLE_STRIP && mode != OF_PRIMITIVE_TRIANGLES) {
		mode = OF_PRIMITIVE_TRIANGLE_STRIP;
	}
	mesh.setMode(mode);

	radiusSegments = radiusSegments+1;
	int capSegs = numCapSegments;
	capSegs = capSegs+1;
	heightSegments = heightSegments+1;
	if(heightSegments < 2) heightSegments = 2;
	if( capSegs < 2 ) bCapped = false;
	if(!bCapped) capSegs=1;

	float angleIncRadius = -1 * (TWO_PI/((float)radiusSegments-1.f));
	float heightInc = height/((float)heightSegments-1.f);
	float halfH = height*.5f;

	float newRad;
	ofVec3f vert;
	ofVec2f tcoord;
	ofVec3f normal;
	ofVec3f up(0,1,0);

	std::size_t vertOffset = 0;

	float maxTexY   = heightSegments-1.f;
	if(capSegs > 0) {
		maxTexY += (capSegs*2)-2.f;
	}
	float maxTexYNormalized = (capSegs-1.f) / maxTexY;

	// add the top cap //
	if(bCapped && capSegs > 0) {
		normal.set(0,-1,0);
		for(int iy = 0; iy < capSegs; iy++) {
			for(int ix = 0; ix < radiusSegments; ix++) {
				newRad = ofMap((float)iy, 0, capSegs-1, 0.0, radius);
				vert.x = cos((float)ix*angleIncRadius) * newRad;
				vert.z = sin((float)ix*angleIncRadius) * newRad;
				vert.y = -halfH;

				tcoord.x = (float)ix/((float)radiusSegments-1.f);
				tcoord.y = ofMap(iy, 0, capSegs-1, 0, maxTexYNormalized);

				mesh.addTexCoord( tcoord );
				mesh.addVertex( vert );
				mesh.addNormal( normal );
			}
		}

		if(mode == OF_PRIMITIVE_TRIANGLES) {
			for(int y = 0; y < capSegs-1; y++) {
				for(int x = 0; x < radiusSegments-1; x++) {
					if(y > 0) {
						// first triangle //
						mesh.addIndex( (y)*radiusSegments + x + vertOffset );
						mesh.addIndex( (y)*radiusSegments + x+1 + vertOffset);
						mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);
					}

					// second triangle //
					mesh.addIndex( (y)*radiusSegments + x+1 + vertOffset);
					mesh.addIndex( (y+1)*radiusSegments + x+1 + vertOffset);
					mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);
				}
			}
		} else {
			for(int y = 0; y < capSegs-1; y++) {
				for(int x = 0; x < radiusSegments; x++) {
					mesh.addIndex( (y)*radiusSegments + x + vertOffset );
					mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);
				}
			}
		}

		vertOffset = mesh.getNumVertices();

	}

	//maxTexY			 = heightSegments-1.f + capSegs-1.f;
	float minTexYNormalized = 0;
	if(bCapped) minTexYNormalized = maxTexYNormalized;
	maxTexYNormalized   = 1.f;
	if(bCapped) maxTexYNormalized = (heightSegments) / maxTexY;

	// cylinder vertices //
	for(int iy = 0; iy < heightSegments; iy++) {
		normal.set(1,0,0);
		for(int ix = 0; ix < radiusSegments; ix++) {

			//newRad = ofMap((float)iy, 0, heightSegments-1, 0.0, radius);
			vert.x = cos((float)ix*angleIncRadius) * radius;
			vert.y = heightInc*((float)iy) - halfH;
			vert.z = sin((float)ix*angleIncRadius) * radius;

			tcoord.x = (float)ix/((float)radiusSegments-1.f);
			tcoord.y = ofMap(iy, 0, heightSegments-1, minTexYNormalized, maxTexYNormalized );

			mesh.addTexCoord( tcoord );
			mesh.addVertex( vert );
			mesh.addNormal( normal );

			normal.rotateRad(-angleIncRadius, up);

		}
	}

	if(mode == OF_PRIMITIVE_TRIANGLES) {
		for(int y = 0; y < heightSegments-1; y++) {
			for(int x = 0; x < radiusSegments-1; x++) {
				// first triangle //
				mesh.addIndex( (y)*radiusSegments + x + vertOffset);
				mesh.addIndex( (y)*radiusSegments + x+1 + vertOffset );
				mesh.addIndex( (y+1)*radiusSegments + x + vertOffset );

				// second triangle //
				mesh.addIndex( (y)*radiusSegments + x+1 + vertOffset );
				mesh.addIndex( (y+1)*radiusSegments + x+1 + vertOffset );
				mesh.addIndex( (y+1)*radiusSegments + x + vertOffset );
			}
		}
	} else {
		for(int y = 0; y < heightSegments-1; y++) {
			for(int x = 0; x < radiusSegments; x++) {
				mesh.addIndex( (y)*radiusSegments + x + vertOffset );
				mesh.addIndex( (y+1)*radiusSegments + x + vertOffset );
			}
		}
	}

	vertOffset = mesh.getNumVertices();

	// add the bottom cap
	if(bCapped && capSegs > 0) {
		minTexYNormalized = maxTexYNormalized;
		maxTexYNormalized   = 1.f;

		normal.set(0, 1,0);
		for(int iy = 0; iy < capSegs; iy++) {
			for(int ix = 0; ix < radiusSegments; ix++) {
				newRad = ofMap((float)iy, 0, capSegs-1, radius, 0.0);
				vert.x = cos((float)ix*angleIncRadius) * newRad;
				vert.z = sin((float)ix*angleIncRadius) * newRad;
				vert.y = halfH;

				tcoord.x = (float)ix/((float)radiusSegments-1.f);
				tcoord.y = ofMap(iy, 0, capSegs-1, minTexYNormalized, maxTexYNormalized);

				mesh.addTexCoord( tcoord );
				mesh.addVertex( vert );
				mesh.addNormal( normal );
			}
		}

		if(mode == OF_PRIMITIVE_TRIANGLES) {
			for(int y = 0; y < capSegs-1; y++) {
				for(int x = 0; x < radiusSegments-1; x++) {
					// first triangle //
					mesh.addIndex( (y)*radiusSegments + x + vertOffset );
					mesh.addIndex( (y)*radiusSegments + x+1 + vertOffset);
					mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);

					if(y < capSegs -1 && capSegs > 2) {
						// second triangle //
						mesh.addIndex( (y)*radiusSegments + x+1 + vertOffset);
						mesh.addIndex( (y+1)*radiusSegments + x+1 + vertOffset);
						mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);
					}
				}
			}
		} else {
			for(int y = 0; y < capSegs-1; y++) {
				for(int x = 0; x < radiusSegments; x++) {
					mesh.addIndex( (y)*radiusSegments + x + vertOffset );
					mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);
				}
			}
		}

		vertOffset = mesh.getNumVertices();

	}

	return mesh;
}

// Cone Mesh //
//--------------------------------------------------------------
ofMesh ofMesh::cone( float radius, float height, int radiusSegments, int heightSegments, int capSegments, ofPrimitiveMode mode ) {
	ofMesh mesh;
	if(mode != OF_PRIMITIVE_TRIANGLE_STRIP && mode != OF_PRIMITIVE_TRIANGLES) {
		mode = OF_PRIMITIVE_TRIANGLE_STRIP;
	}
	mesh.setMode(mode);

	radiusSegments = radiusSegments+1;
	capSegments = capSegments+1;
	heightSegments = heightSegments+1;
	if(heightSegments < 2) heightSegments = 2;
	int capSegs = capSegments;
	if( capSegs < 2 ) {
		capSegs = 0;
	}


	float angleIncRadius = -1.f * ((TWO_PI/((float)radiusSegments-1.f)));
	float heightInc = height/((float)heightSegments-1);
	float halfH = height*.5f;

	float newRad;
	ofVec3f vert;
	ofVec3f normal;
	ofVec2f tcoord;
	ofVec3f up(0,1,0);

	std::size_t vertOffset = 0;

	float maxTexY = heightSegments-1.f;
	if(capSegs > 0) {
		maxTexY += capSegs-1.f;
	}

	ofVec3f startVec(0, -halfH-1.f, 0);

	// cone vertices //
	for(int iy = 0; iy < heightSegments; iy++) {
		normal.set(1,0,0);
		for(int ix = 0; ix < radiusSegments; ix++) {

			newRad = ofMap((float)iy, 0, heightSegments-1, 0.0, radius);
			vert.x = cos((float)ix*angleIncRadius) * newRad;
			vert.y = heightInc*((float)iy) - halfH;
			vert.z = sin((float)ix*angleIncRadius) * newRad;

			tcoord.x = (float)ix/((float)radiusSegments-1.f);
			tcoord.y = (float)iy/((float)maxTexY);

			mesh.addTexCoord( tcoord );
			mesh.addVertex( vert );

			if(iy == 0) {
				newRad = 1.f;
				vert.x = cos((float)ix*angleIncRadius) * newRad;
				vert.y = heightInc*((float)iy) - halfH;
				vert.z = sin((float)ix*angleIncRadius) * newRad;
			}

			ofVec3f diff = vert-startVec;
			ofVec3f crossed = up.getCrossed(vert);
			normal = crossed.getNormalized();
			normal = crossed.getPerpendicular(diff);

			normal.normalize();

			mesh.addNormal( normal );

		}
	}

	if(mode == OF_PRIMITIVE_TRIANGLES) {
		for(int y = 0; y < heightSegments-1; y++) {
			for(int x = 0; x < radiusSegments-1; x++) {
				if(y > 0){
					// first triangle //
					mesh.addIndex( (y)*radiusSegments + x );
					mesh.addIndex( (y)*radiusSegments + x+1 );
					mesh.addIndex( (y+1)*radiusSegments + x );
				}

				// second triangle //
				mesh.addIndex( (y)*radiusSegments + x+1 );
				mesh.addIndex( (y+1)*radiusSegments + x+1 );
				mesh.addIndex( (y+1)*radiusSegments + x );
			}
		}
	} else {
		for(int y = 0; y < heightSegments-1; y++) {
			for(int x = 0; x < radiusSegments; x++) {
				mesh.addIndex( (y)*radiusSegments + x );
				mesh.addIndex( (y+1)*radiusSegments + x );
			}
		}
	}

	vertOffset = mesh.getNumVertices();
	float maxTexYNormalized = (heightSegments-1.f) / maxTexY;

	// add the cap //
	normal.set(0,1,0);
	for(int iy = 0; iy < capSegs; iy++) {
		for(int ix = 0; ix < radiusSegments; ix++) {
			newRad = ofMap((float)iy, 0, capSegs-1, radius, 0.0);
			vert.x = cos((float)ix*angleIncRadius) * newRad;
			vert.z = sin((float)ix*angleIncRadius) * newRad;
			vert.y = halfH;

			tcoord.x = (float)ix/((float)radiusSegments-1.f);
			tcoord.y = ofMap(iy, 0, capSegs-1, maxTexYNormalized, 1.f);

			mesh.addTexCoord( tcoord );
			mesh.addVertex( vert );
			mesh.addNormal( normal );
		}
	}

	if(mode == OF_PRIMITIVE_TRIANGLES) {
		if( capSegs > 0 ) {
			for(int y = 0; y < capSegs-1; y++) {
				for(int x = 0; x < radiusSegments-1; x++) {
					// first triangle //
					mesh.addIndex( (y)*radiusSegments + x + vertOffset );
					mesh.addIndex( (y)*radiusSegments + x+1 + vertOffset);
					mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);

					if(y < capSegs-1) {
						// second triangle //
						mesh.addIndex( (y)*radiusSegments + x+1 + vertOffset);
						mesh.addIndex( (y+1)*radiusSegments + x+1 + vertOffset);
						mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);
					}
				}
			}
		}
	} else {
		if(capSegs > 0 ) {
			for(int y = 0; y < capSegs-1; y++) {
				for(int x = 0; x < radiusSegments; x++) {
					mesh.addIndex( (y)*radiusSegments + x + vertOffset );
					mesh.addIndex( (y+1)*radiusSegments + x + vertOffset);
				}
			}
		}
	}

	return mesh;
}


// Box Mesh //
//--------------------------------------------------------------
ofMesh ofMesh::box( float width, float height, float depth, int resX, int resY, int resZ ) {
	// mesh only available as triangles //
	ofMesh mesh;
	mesh.setMode( OF_PRIMITIVE_TRIANGLES );

	resX = resX + 1;
	resY = resY + 1;
	resZ = resZ + 1;

	if( resX < 2 ) resX = 0;
	if( resY < 2 ) resY = 0;
	if( resZ < 2 ) resZ = 0;

	// halves //
	float halfW = width * .5f;
	float halfH = height * .5f;
	float halfD = depth * .5f;

	ofVec3f vert;
	ofVec2f texcoord;
	ofVec3f normal;
	std::size_t vertOffset = 0;

	// TRIANGLES //

	// Front Face //
	normal.set(0, 0, 1);
	// add the vertexes //
	for(int iy = 0; iy < resY; iy++) {
		for(int ix = 0; ix < resX; ix++) {

			// normalized tex coords //
			texcoord.x = ((float)ix/((float)resX-1.f));
			texcoord.y = ((float)iy/((float)resY-1.f));

			vert.x = texcoord.x * width - halfW;
			vert.y = texcoord.y * height - halfH;
			vert.z = halfD;

			mesh.addVertex(vert);
			mesh.addTexCoord(texcoord);
			mesh.addNormal(normal);
		}
	}

	for(int y = 0; y < resY-1; y++) {
		for(int x = 0; x < resX-1; x++) {
			// first triangle //
			mesh.addIndex((y)*resX + x + vertOffset);
			mesh.addIndex((y)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x + vertOffset);

			// second triangle //
			mesh.addIndex((y)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x + vertOffset);
		}
	}

	vertOffset = mesh.getNumVertices();


	// Right Side Face //
	normal.set(1, 0, 0);
	// add the vertexes //
	for(int iy = 0; iy < resY; iy++) {
		for(int ix = 0; ix < resZ; ix++) {

			// normalized tex coords //
			texcoord.x = ((float)ix/((float)resZ-1.f));
			texcoord.y = ((float)iy/((float)resY-1.f));

			//vert.x = texcoord.x * width - halfW;
			vert.x = halfW;
			vert.y = texcoord.y * height - halfH;
			vert.z = texcoord.x * -depth + halfD;

			mesh.addVertex(vert);
			mesh.addTexCoord(texcoord);
			mesh.addNormal(normal);
		}
	}

	for(int y = 0; y < resY-1; y++) {
		for(int x = 0; x < resZ-1; x++) {
			// first triangle //
			mesh.addIndex((y)*resZ + x + vertOffset);
			mesh.addIndex((y)*resZ + x+1 + vertOffset);
			mesh.addIndex((y+1)*resZ + x + vertOffset);

			// second triangle //
			mesh.addIndex((y)*resZ + x+1 + vertOffset);
			mesh.addIndex((y+1)*resZ + x+1 + vertOffset);
			mesh.addIndex((y+1)*resZ + x + vertOffset);
		}
	}

	vertOffset = mesh.getNumVertices();

	// Left Side Face //
	normal.set(-1, 0, 0);
	// add the vertexes //
	for(int iy = 0; iy < resY; iy++) {
		for(int ix = 0; ix < resZ; ix++) {

			// normalized tex coords //
			texcoord.x = ((float)ix/((float)resZ-1.f));
			texcoord.y = ((float)iy/((float)resY-1.f));

			//vert.x = texcoord.x * width - halfW;
			vert.x = -halfW;
			vert.y = texcoord.y * height - halfH;
			vert.z = texcoord.x * depth - halfD;

			mesh.addVertex(vert);
			mesh.addTexCoord(texcoord);
			mesh.addNormal(normal);
		}
	}

	for(int y = 0; y < resY-1; y++) {
		for(int x = 0; x < resZ-1; x++) {
			// first triangle //
			mesh.addIndex((y)*resZ + x + vertOffset);
			mesh.addIndex((y)*resZ + x+1 + vertOffset);
			mesh.addIndex((y+1)*resZ + x + vertOffset);

			// second triangle //
			mesh.addIndex((y)*resZ + x+1 + vertOffset);
			mesh.addIndex((y+1)*resZ + x+1 + vertOffset);
			mesh.addIndex((y+1)*resZ + x + vertOffset);
		}
	}

	vertOffset = mesh.getNumVertices();


	// Back Face //
	normal.set(0, 0, -1);
	// add the vertexes //
	for(int iy = 0; iy < resY; iy++) {
		for(int ix = 0; ix < resX; ix++) {

			// normalized tex coords //
			texcoord.x = ((float)ix/((float)resX-1.f));
			texcoord.y = ((float)iy/((float)resY-1.f));

			vert.x = texcoord.x * -width + halfW;
			vert.y = texcoord.y * height - halfH;
			vert.z = -halfD;

			mesh.addVertex(vert);
			mesh.addTexCoord(texcoord);
			mesh.addNormal(normal);
		}
	}

	for(int y = 0; y < resY-1; y++) {
		for(int x = 0; x < resX-1; x++) {
			// first triangle //
			mesh.addIndex((y)*resX + x + vertOffset);
			mesh.addIndex((y)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x + vertOffset);

			// second triangle //
			mesh.addIndex((y)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x + vertOffset);
		}
	}

	vertOffset = mesh.getNumVertices();


	// Top Face //
	normal.set(0, -1, 0);
	// add the vertexes //
	for(int iy = 0; iy < resZ; iy++) {
		for(int ix = 0; ix < resX; ix++) {

			// normalized tex coords //
			texcoord.x = ((float)ix/((float)resX-1.f));
			texcoord.y = ((float)iy/((float)resZ-1.f));

			vert.x = texcoord.x * width - halfW;
			//vert.y = texcoord.y * height - halfH;
			vert.y = -halfH;
			vert.z = texcoord.y * depth - halfD;

			mesh.addVertex(vert);
			mesh.addTexCoord(texcoord);
			mesh.addNormal(normal);
		}
	}

	for(int y = 0; y < resZ-1; y++) {
		for(int x = 0; x < resX-1; x++) {
			// first triangle //
			mesh.addIndex((y)*resX + x + vertOffset);
			mesh.addIndex((y)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x + vertOffset);

			// second triangle //
			mesh.addIndex((y)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x + vertOffset);
		}
	}

	vertOffset = mesh.getNumVertices();


	// Bottom Face //
	normal.set(0, 1, 0);
	// add the vertexes //
	for(int iy = 0; iy < resZ; iy++) {
		for(int ix = 0; ix < resX; ix++) {

			// normalized tex coords //
			texcoord.x = ((float)ix/((float)resX-1.f));
			texcoord.y = ((float)iy/((float)resZ-1.f));

			vert.x = texcoord.x * width - halfW;
			//vert.y = texcoord.y * height - halfH;
			vert.y = halfH;
			vert.z = texcoord.y * -depth + halfD;

			mesh.addVertex(vert);
			mesh.addTexCoord(texcoord);
			mesh.addNormal(normal);
		}
	}

	for(int y = 0; y < resZ-1; y++) {
		for(int x = 0; x < resX-1; x++) {
			// first triangle //
			mesh.addIndex((y)*resX + x + vertOffset);
			mesh.addIndex((y)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x + vertOffset);

			// second triangle //
			mesh.addIndex((y)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x+1 + vertOffset);
			mesh.addIndex((y+1)*resX + x + vertOffset);
		}
	}

	return mesh;
}


//--------------------------------------------------------------

/// Returns an ofMesh representing an XYZ coordinate system.
ofMesh ofMesh::axis( float size ) {
	ofMesh mesh;

	// mesh only available as wireframe //
	mesh.setMode(OF_PRIMITIVE_LINES);

	ofVec3f vertices[6] = {
		ofVec3f(0,0,0),
		ofVec3f(size,0,0),
		ofVec3f(0,0,0),
		ofVec3f(0,size,0),
		ofVec3f(0,0,0),
		ofVec3f(0,0,size),
	};
	ofFloatColor colors[6] = {
		ofColor::red,
		ofColor::red,
		ofColor::green,
		ofColor::green,
		ofColor::blue,
		ofColor::blue,
	};

	mesh.addVertices(vertices, 6);
	mesh.addColors(colors, 6);

	return mesh;
}

//--------------------------------------------------------------


ofMeshFace::ofMeshFace()
:bHasNormals(false)
,bHasColors(false)
,bHasTexcoords(false)
,bFaceNormalDirty(false)
{
}

const ofVec3f & ofMeshFace::getFaceNormal() const{
	if(bFaceNormalDirty) calculateFaceNormal();
	return faceNormal;
}

void ofMeshFace::calculateFaceNormal() const{
	ofVec3f U, V;

	U = (vertices[1]-vertices[0]);
	V = (vertices[2]-vertices[0]);

	faceNormal = U.getCrossed(V);
	faceNormal.normalize();
	bFaceNormalDirty = false;
}

void ofMeshFace::setVertex( ofIndexType index, const ofVec3f& v ) {
	vertices[index].set( v );
	bFaceNormalDirty = true;
}

const ofVec3f& ofMeshFace::getVertex( ofIndexType index ) const{
	return vertices[index];
}

void ofMeshFace::setNormal( ofIndexType index, const ofVec3f& n ) {
	normals[index] = n;
	bHasNormals = true;
}

const ofVec3f& ofMeshFace::getNormal( ofIndexType index ) const{
	return normals[ index ];
}

void ofMeshFace::setColor( ofIndexType index, const ofFloatColor& color ) {
	colors[index] = color;
	bHasColors = true;
}

const ofFloatColor& ofMeshFace::getColor( ofIndexType index) const{
	return colors[index];
}

void ofMeshFace::setTexCoord( ofIndexType index, const ofVec2f& tCoord ) {
	texCoords[index] = tCoord;
	bHasTexcoords = true;
}

const ofVec2f& ofMeshFace::getTexCoord( ofIndexType index ) const{
	return texCoords[index];
}

void ofMeshFace::setHasColors( bool bColors ) {
	bHasColors = bColors;
}

void ofMeshFace::setHasNormals( bool bNormals ) {
	bHasNormals = bNormals;
}

void ofMeshFace::setHasTexcoords( bool bTexcoords ) {
	bHasTexcoords = bTexcoords;
}

bool ofMeshFace::hasColors() const{
	return bHasColors;
}

bool ofMeshFace::hasNormals() const{
	return bHasNormals;
}

bool ofMeshFace::hasTexcoords() const{
	return bHasTexcoords;
}
