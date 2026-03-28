#include <utility>
#include <iostream>
#include "ResourceManager.h"


Video::Video(const std::string title) : _title(std::move(title)) {}

void Video::play() const {
    std::cout << "Playing title: " << _title << std::endl;
}

std::unique_ptr<MediaAsset> createAsset(std::string title){
    return std::make_unique<Video> (std::move(title));
}
