#pragma once

namespace Effort
{
	using int8 = __int8;
	using int16 = __int16;
	using int32 = __int32;
	using int64 = __int64;

	using uint8 = unsigned __int8;
	using uint16 = unsigned __int16;
	using uint32 = unsigned __int32;
	using uint64 = unsigned __int64;

	template<class T, std::size_t size>
	using Array = std::array<T, size>;
	template<class T>
	using Vector = std::vector<T>;
	template<class T>
	using List = std::list<T>;
	template<class Key, class Type>
	using Map = std::map<Key, Type>;
	template<class Key, class Type>
	using MultiMap = std::multimap<Key, Type>;
	template<class Key, class Type, class HashType = std::hash<Key>>
	using HashMap = std::unordered_map<Key, Type, HashType>;
	template<class Key, class Type, class HashType = std::hash<Key>>
	using MultiHashMap = std::unordered_multimap<Key, Type, HashType>;
	template<class T>
	using Set = std::set<T>;
	template<class Key, class HashType = std::hash<Key>>
	using HashSet = std::unordered_set<Key,HashType>;
	template<class T>
	using Stack = std::stack<T>;
	template<class T>
	using Queue = std::queue<T>;

	template<class T>
	using SPtr = std::shared_ptr<T>;
	template<class T>
	using UPtr = std::unique_ptr<T>;
	template<class T>
	using WPtr = std::weak_ptr<T>;
	template<class T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
}