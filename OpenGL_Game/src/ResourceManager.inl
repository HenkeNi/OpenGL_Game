#include "pch.h"
#include "ResourceManager.h"


template <typename Resource, typename Identifier>
template <typename... Args>
void ResourceManager<Resource, Identifier>::load(Identifier id, Args&&... args)
{
	auto resource{ std::make_unique<Resource>() };
	if (!resource->loadFromFile(std::forward<Args>(args)...))
		throw std::runtime_error("Failed to load resource");

	insertResource(id, std::move(resource));
}

template <typename Resource, typename Identifier>
Resource& ResourceManager<Resource, Identifier>::getResource(Identifier id)
{
	auto found{ m_resourceMap.find(id) };
	assert(found != m_resourceMap.end());

	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceManager<Resource, Identifier>::getResource(Identifier id) const
{
	auto found{ m_resourceMap.find(id) };
	assert(found != m_resourceMap.end());

	return *found->second;
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource)
{
	auto inserted{ m_resourceMap.insert(std::make_pair(id, std::move(resource))) };
	assert(inserted.second);
}