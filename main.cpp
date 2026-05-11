#include <opencv2/opencv.hpp>
#include <filesystem>

int main(int argc, char* argv[]){

    if (argc < 3){
        std::cout << "You need choose Filter and an Image\n" << std::endl;
        std::cout << "Example ./imgcolorset --rgb image\n\n ./imgcolorset --hsv image\n\n ./imgcolorset --gray image" << std::endl;
        exit(-1);
    }

    if (std::string(argv[1]) == "--hsv") {
        cv::Mat bgr_image = cv::imread(argv[2]);
        if (bgr_image.empty()){
            std::cerr << "Error Open image" << std::endl;
            return -1;
        }
        cv::Mat hsv_image;
        cv::cvtColor(bgr_image, hsv_image, cv::COLOR_BGR2HSV);
        std::filesystem::path input(argv[2]);
        std::string output = "hsv_" + input.stem().string() + ".png";

        bool sucess = cv::imwrite(output, hsv_image);

        if(sucess){
            std::cout << "HSV image saved!" << std::endl;
        } else {
            std::cerr << "Falied to save the image." << std::endl;
        }

    }


    return 0;
}