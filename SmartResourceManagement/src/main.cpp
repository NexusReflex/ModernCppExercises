#include <iostream>
#include "ResourceManager.h"

int main(){
    std::string title;
    std::cout << "Type a movie title...\n";
    std::getline(std::cin, title);

    auto video_asset = createAsset(title);

    // EXPERIMENT A: The Copy Attempt
    // Un-comment the line below and try to compile. It should FAIL.
    // std::unique_ptr<MediaAsset> another_ptr = video_asset; 

    // EXPERIMENT B: The Move -> moves smart pointer content to a new smart pointer. video_asset becomes nullptr.
    std::unique_ptr<MediaAsset> moved_asset = std::move(video_asset);
    std::cout << "Asset moved to new pointer.\n";

    // EXPERIMENT C: The Crash Test
    // What happens if you call this now?
    if (!video_asset) {
        std::cout << "video_asset is now null/empty!\n";
    }
    
    moved_asset->play(); // This works.
    // video_asset->play(); // UNCOMMENT THIS TO SEE A RUNTIME CRASH.
}