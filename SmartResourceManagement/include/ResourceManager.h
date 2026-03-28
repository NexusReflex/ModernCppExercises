#pragma once

#include <memory>
#include <string>
#include <utility>

class MediaAsset{

    public:
        virtual ~MediaAsset() = default; // base class needs virtual destructor

        virtual void play() const = 0; // The "= 0" makes it pure virtual

};

class Video : public MediaAsset{

    public:
        explicit Video(std::string title); // no const, otherwise std::move cannot move the string

        void play() const override;
    
    private:
        std::string _title;
};

std::unique_ptr<MediaAsset> createAsset(std::string asset_title);