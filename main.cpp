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

    if (std::string(argv[1]) == "--rgb") {
        cv::Mat bgr_img = cv::imread(argv[2]);
    if (bgr_img.empty()) {
        std::cerr << "Error Open image" << std::endl;
        return -1;
    }
    cv::Mat rgb_img;
    cv::cvtColor(bgr_img, rgb_img, cv::COLOR_BGR2RGB);  // BGR → RGB
    std::filesystem::path input(argv[2]);
    std::string outputrgb = "rgb_" + input.stem().string() + ".png";
    bool sucess = cv::imwrite(outputrgb, rgb_img);
    if (sucess) {
        std::cout << "RGB Image Saved!" << std::endl;
    } else {
        std::cerr << "Failed to save RGB image" << std::endl;
    }
    }

    if (std::string(argv[1]) == "--gray"){
        cv::Mat colorImg = cv::imread(argv[2]);
        if (colorImg.empty()){
            std::cerr << "Falied Load Image" << std::endl;
            return -1;
        }
        cv::Mat grayImage;
        cv:cvtColor(colorImg, grayImage, cv::COLOR_BGR2GRAY);
        std::filesystem::path input(argv[2]);
        std::string outputGray = "gray_" + input.stem().string() + ".png";

        bool sucess = cv::imwrite(outputGray, grayImage);

        if (sucess){
            std::cout << "Image Gray Scale Saved!" << std::endl;
        } else {
            std::cerr << "Falied  to save Gray Image" << std::endl;
        }


    }


    return 0;
}