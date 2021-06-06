#include "GenreControl.h"

#include "../hjson/hjson-ex.h"

namespace Tatelier::SongSelect {
    GenreControl::GenreControl()
    {
    }

    TLRESULT GenreControl::Init(const std::string& filePath)
    {
        auto hjson = HjsonEx::Load(filePath);

        if (HjsonEx::EQs(hjson, "ImageRootFolder", &imageRootFolder, "SongSelect/Genres") != HjsonEx::SUCCESS) {
            // TODO: �G���[����
        }

        Hjson::Value arr;

        if (HjsonEx::EQa(hjson, "Genres", &arr, Hjson::Value()) != HjsonEx::SUCCESS) {
            // TODO: �G���[����
        }

        return TL_SUCCESS;
    }
}

