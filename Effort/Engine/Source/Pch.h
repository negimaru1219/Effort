#pragma once

#define NOMINMAX

// ComPtr
#include <wrl/client.h>

// ���������[�N�̊��m
#include <crtdbg.h>

// �R���e�i
#include <vector>
#include <list>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>

// ���
#include <memory>
#include <functional>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <chrono>
#include <optional>
#include <ctime>
#include <cstdlib>
#include <cstdint>
#include <iterator>
#include <execution>

// �}���`�X���b�h
#include <thread>
#include <atomic>
#include <mutex>
#include <future>

// ������
#include <string>
#include <string_view>

// ���l����
#include <numeric>
#include <random>

// ���o�̓X�g���[��
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iomanip>
#include <iostream>

// Windows
#include <windowsx.h>
#pragma comment(lib, "winmm.lib")

#include <DirectXMath.h>

// DirectX12
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")

// Engine
#include "Core/Platform.h"
#include "Math/Math.h"