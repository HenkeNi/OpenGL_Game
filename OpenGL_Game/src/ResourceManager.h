#pragma once

//#include <memory>
//#include <unordered_map>

template <typename Resource, typename Identifier>
class ResourceManager
{
public:
	template <typename... Args>
	void load(Identifier id, Args&&... args);

	Resource&		getResource(Identifier id);
	const Resource& getResource(Identifier id) const;

private:
	void insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
	std::unordered_map<Identifier, std::unique_ptr<Resource>> m_resourceMap;

};

#include "ResourceManager.inl"