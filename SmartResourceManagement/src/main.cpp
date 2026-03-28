#include "ResourceManager.h"

int main(){
    std::string title;

    std::cout << "Type a movie title...\n";
    std::getline(std::cin, title);

    auto video_asset = createAsset(title);

    video_asset->play();
}