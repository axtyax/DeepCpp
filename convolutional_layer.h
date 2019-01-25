#ifndef DEEPCPP_CONVOLUTIONAL_LAYER_H
#define DEEPCPP_CONVOLUTIONAL_LAYER_H

#include "layer.h"

#include <vector>
#include <functional>
#include <iostream>

namespace dcpp {

//The feedforward layer implements basic backpropagation techniques used for feedforward networks
class ConvolutionalLayer : public Layer {

    private:
    
        int input_size;
        int output_scale;
        int featuremap_width;
        int featuremap_height;
        int kernel_size;
        int num_weights;
    
        std::function<int(std::vector<int>)> 3d_map_function;
        int 3d_map(std::vector<int> i, int imheight, int imwidth) {
            return i[0] + i[1]*imheight + i[2]*imheight*imwidth;
        }

        //DOT PRODUCT FUNCTION
        double matrix_dot_product(Signal &mat, Signal& kernels, int x, int y, int m) {
            return 0.0;
        }

        Signal 2d_convolution(Signal& mat, Signal& kernels) {
            Signal result(mat.get_size()*output_scale);
            int kernel_bezel = (kernel_size-1)/2;
            for (int k = 0; k < input_size; k++) {
                for (int dk = 0; dk < output_scale; dk++) {

                    int current_kernel = k*output_scale+dk;
                    for (int x = 0; x < featuremap_height; x++) {
                        for (int y = 0; y < featuremap_width; y++) {
                            if (x >= featuremap_height - kernel_bezel || y >= featuremap_width - kernel_bezel) {
                                result[x][y][current_kernel] = 0;
                            }
                            else {
                                
                            }   
                        }
                    }

                }

            }
        }

    public:

        ConvolutionalLayer(int insize, int outscale, std::tuple<int,int> fmapsize, int kernelsize, double lwb, double lub) {
            input_size = insize; output_scale = outscale;
            featuremap_height = std::get<0>(fmapsize); featuremap_width = std::get<1>(fmapsize);
            kernel_size = kernelsize;
            num_weights = pow(kernel_size,2)*input_size*output_scale;
            
            3d_map_function = [imh = featuremap_height, imw = featuremap_width](std::vector<int> i) {
                return 3d_map(i,imh,imw);
            }

            weights = Signal(num_weights);
            weights.randomize(lwb,lub);
            weights.set_map(3dm);
        }

        Signal& process(Signal& input) {

        }

        Signal& back_propagate(Signal& next_gradient) {

        }

};

}

#endif