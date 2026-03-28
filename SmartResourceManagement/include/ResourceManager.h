#pragma once

#include <memory>
#include <string>
#include <utility>
#include <iostream>

class MediaAsset{

    public:
        virtual ~MediaAsset() = default; // base class needs virtual destructor

        virtual void play() const = 0; // The "= 0" makes it pure virtual

};

class Video : public MediaAsset{

    public:
        explicit Video(const std::string title);

        void play() const override;
    
    private:
        std::string _title;
};

std::unique_ptr<MediaAsset> createAsset(std::string asset_title);