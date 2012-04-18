#pragma once
#include <Windows.h>
#include <D3D10.h>
#include <D3DX10.h>
#include <iostream>
#include <vector>

#include <sstream>
#include <fstream>

using namespace std;

#define SCREENWIDTH (1024)
#define _SCREENHEIGHT (768)

enum Direction{ D_NORTH, D_SOUTH, D_EAST, D_WEST, D_SIZE };

#define SAFE_DELETE(x) if(x) { delete(x); (x) = NULL; }
#define SAFE_RELEASE(x) if(x){(x)->Release();(x) = NULL;}