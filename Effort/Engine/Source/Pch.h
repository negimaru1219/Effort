#pragma once

#define NOMINMAX

// ComPtr
#include <wrl/client.h>

// メモリリークの感知
#include <crtdbg.h>

// コンテナ
#include <vector>
#include <list>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>

// 一般
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

// マルチスレッド
#include <thread>
#include <atomic>
#include <mutex>
#include <future>

// 文字列
#include <string>
#include <string_view>

// 数値処理
#include <numeric>
#include <random>

// 入出力ストリーム
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