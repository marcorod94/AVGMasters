#include "Application.h"
#include "ModuleTriangle.h"
#include "GL/glew.h"

ModuleTriangle::ModuleTriangle() {

}

ModuleTriangle::~ModuleTriangle() {

}

bool ModuleTriangle::Init() {
	float buffer_data[] = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,  1.0f, 0.0f };
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer_data), buffer_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return true;
}

update_status ModuleTriangle::Update() {
	
	glEnableVertexAttribArray(0); // attribute 0
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3); 
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return UPDATE_CONTINUE;
}

bool ModuleTriangle::CleanUp() {
	return true;
}