#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

#include <memory>

#include <glm.hpp>
#include <gtx/quaternion.hpp>

#include<chrono>


typedef std::chrono::high_resolution_clock high_resolution_clock;
typedef std::chrono::steady_clock::time_point time_point;
typedef std::chrono::seconds seconds;
typedef std::chrono::milliseconds milliseconds;

inline void print(const std::string& text) {
	std::cout << text << std::endl;
}

inline void err(const std::string& text) {
	std::cerr << text << std::endl;
}

inline void todo(const std::string& text) {
	std::cerr << "This functionality has not yet been implemented: " << text << std::endl;
}

inline float max(float a, float b) {
    return a > b ? a : b;
}

inline float min(float a, float b) {
    return a < b ? a : b;
}

inline float clamp(float v, float minVal, float maxVal) {
	if (v < minVal) {
		v = minVal;
	}

	if (v > maxVal) {
		v = maxVal;
	}

	return v;
}

template<class T>
inline void printArray(T* arr, const std::string& name, int len) {
	std::cout << name << ": ";
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

typedef unsigned int uint;
typedef unsigned char uint8;

typedef glm::vec2 vec2;
typedef glm::ivec2 ivec2;
typedef glm::vec3 vec3;
typedef glm::vec4 vec4;
typedef glm::mat4x4 mat4;
typedef glm::quat quat;
typedef std::string string;

inline mat4 translation(vec3 t) {
	return glm::translate(glm::identity<mat4>(), t);
}

inline mat4 scale(vec3 t) {
	return glm::scale(glm::identity<mat4>(), t);
}

inline mat4 rotation(quat r) {
	return glm::toMat4(r);
}

inline int find(char* str, int len, char c, int start) {
	for (int i = start; i < len; i++) {
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}