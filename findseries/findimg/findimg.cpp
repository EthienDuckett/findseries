#include <iostream>
#include <string>
// #include <vector>
#include <fstream>
std::string input;
std::string vchar;
std::string urlname;
unsigned long len;
unsigned long mod;
// std::vector<std::string> urls;



// substr is the most non-working command I have ever seen. it just breaks...
std::string mysub(std::string word, unsigned int start, unsigned int end){
    std::string savings;
    for (unsigned int c=start; c<end; c++){
        savings+=word[c];
    }
    return savings;
}

//
// TO DO!
// not case sensitive!!!
// maybe open vim or nano so the person can copy and paste the code in instead of messing around?

// also
// https://discord.com/new/jobs/assets/a7fb8707e004a750e7bf5a6172c14b6e.jpg
// https://discord.com/assets/a7fb8707e004a750e7bf5a6172c14b6e.jpg

int main(){
// I just realized my code is an absolute mess
    std::ofstream filestream("storage/imgout.txt");
    std::ofstream filestream2("storage/imgtype.txt");
    std::ifstream filestream3("userinput.txt");
if (filestream.is_open() && filestream2.is_open() && filestream3.is_open()){



    std::cout << "enter the domain name." << std::endl;
    std::getline(std::cin, urlname);
    // std::cout << "You must put all of the code into a file which has just been created, it is named \'userinput.txt\'" << std::endl;
    // This system can't take in enough input
    // while (input != "next"){
    //     vchar+=input;
    //     std:getline(std::cin, input);
    // }

// getlines from userinput.txt until it has reached the end of the document
    while (std::getline(filestream3, input)){
        vchar+=input;
    }

    // std::cout << "vchar has a capacity of " << vchar.capacity() << std::endl;
    // what is the point in getting a slice if I can just use substr... is it faster?
    len = vchar.length();
    for (unsigned long i=0; i < len; i++){

        if (mysub(vchar, i, i+4) == "<img"){
            std::cout << "omg img" << std::endl;

            while (mysub(vchar, i, i+3) != "src" && i+3 < len){
                i++;
            }
            while (vchar[i] != '\'' && vchar[i] != '\"' && i < len){
                i++;
            }

// handle http and https

            if (mysub(vchar, i+1, i+5) == "http"){
                // std::cout << "we found http!" << std::endl;
                i+=1;
                mod=i;
                while (vchar[mod] != '\'' && vchar[mod] != '\"' && mod < len){
                    mod++;
                }
                filestream << mysub(vchar, i, mod) << std::endl;
                i=mod;
            }else if (mysub(vchar, i, i+3) == "\'//" || mysub(vchar, i, i+3) == "\"//"){
                i+=1;
                mod=i;
                while (vchar[mod] != '\'' && vchar[mod] != '\"' && mod < len){
                    mod++;
                }
                if (mysub(urlname, 0, 5) == "http:"){
                    filestream << "http:";
                }else if (mysub(urlname, 0, 5) == "https"){
                    filestream << "https:";
                }
                filestream << mysub(vchar, i, mod) << std::endl;
                i=mod;

            }else if (mysub(vchar, i, i+2) == "\'/" || mysub(vchar, i, i+2) == "\"/" && mod < len){
                i+=1;
                mod=i;
                while (vchar[mod] != '\'' && vchar[mod] != '\"' && mod < len){
                    mod++;
                }
                filestream << urlname;
                filestream << mysub(vchar, i, mod) << std::endl;
                i=mod;
            }
            // else if (){
            //
            // }
// handle singular / thing





        }
    }

    // filestream << mysub(vchar, i, mod) << std::endl;
    std::cout << std::endl;
    filestream.close();
    filestream2.close();
    filestream3.close();
}else{
    // put the compiled name here instead
    std::cout << "this program needs a file named \'userinput.txt\' to operate, please create it in the same folder as findimg.cpp" << std::endl;
    std::cout << "file imgout.txt, imgname.txt and/or imgtype.txt could not be created" << std::endl;
}
    std::ifstream filestream11("storage/imgout.txt");
    std::ofstream filestream12("storage/imgname.txt");
    unsigned int slashspot=0;
    if (filestream11.is_open() && filestream12.is_open()){
        while (getline(filestream11, input)){
            len = input.length();

            for (unsigned int c=len; c > 0; c--){
                if (input[c] == '/'){
                    filestream12 << mysub(input, c+1, len) << std::endl;


// I PUT C=0 HERE AND IT MADE A SEGMENTATION ERROR, SO I DELETED ALL OF MY STUFF!? NOOOO

                    c=1;
                }
            }

        }
    }else{
        std::cout << "imgout.txt could not be found or imgname.txt could not be created" << std::endl;
    }

    return 0;
}
// <img src="http://animage.jpg"></img>
// <img src="https://animage.jpg"></img>
// <img src="/animage.jpg"></img>

// <img src='http://animage.jpg'></img>
// <img src='https://animage.jpg'></img>
// <img src='/animage.jpg'></img>

// <div class="carouselItemOuter-Y7J3EE"><div class="carouselItemContainer-3uScNU"><img class="carouselItemImage-dVRl3_" src="/assets/4e02c7c5f23caa526b88ec7aafd3e946.jpg" srcSet="/assets/2101ed4e97dfcb6d27b2118e24f14ef9.jpg 2x" alt=""/></div></div></div><div class="item-3rPEHJ" style="width:640px"><div class="carouselItemOuter-Y7J3EE"><div class="carouselItemContainer-3uScNU"><img class="carouselItemImage-dVRl3_" src="/assets/450bee0b2b2d76d0fb4d6d4402be550e.jpg" srcSet="/assets/50e27582392120f287d72cea89439e57.jpg 2x" alt=""/></div></div></div><div class="item-3rPEHJ" style="width:640px">
