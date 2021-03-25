
#include<stdexcept>
#include "snowman.hpp"
#include <array>
using namespace std ;


namespace ariel {
const int hat=0, nose=1, left_eye=2, right_eye=3, left_hand=4, right_hand=5, torso=6, base=7;
const int min = 1, max = 4 ,length=8, hex_base=10;
 string print_hat(int num) {
 if (num == 3) {
      return "   _   \n  /_\\ \n";
      }
 if (num == 2) {
     return "  ___  \n ..... \n";
      }
 if (num == 1) {
     return "       \n _===_ \n";
        }
    return "  ___  \n (_*_) \n"; 

}

  
   string print_nose(int num) {
        if (num == 1) {
            return ",";
        }
        if (num == 2) {
            return ".";
        }
        if (num == 3) {
            return "_";
        }
        return " "; 
    }

      string print_eye(int num) {
        if (num == 1){
            return ".";
        }
        if (num == 2) {
            return "o";
        }
        if (num == 3) {
            return "O";
        }
        return "-"; 
    }

    string print_base(int num) {
        if (num == 1) {
            return " ( : ) \n";
        }
        if (num == 2) {
            return " (\" \") \n";
        }
        if (num == 3) {
            return " (___) \n";
        }
        return " (   ) \n";
    }


    string print_torso(int num) {
        if (num == 1) {
            return " : ";
        }
        if (num == 2) {
            return "] [";
        }
        if (num == 3) {
            return "> <";
        }
        return "   ";
    }


    string print3(int nose, int left, int right, int x, int y) {
        string string;
        if (x == 2) {
            string = "\\";
        }
        else {
            string = " ";
        }
        string = string + "(";
        string = string + print_eye(left);
        string = string + print_nose(nose);
        string = string + print_eye(right);
        string = string + ")";
        if (y == 2) {
            string = string + "/";
        }
        else {
            string = string + " ";
        }
        string = string + "\n";
        return string;
    }

    string print4(int x, int y, int torso) {
        string string;
        if (x == 1) {
            string = "<";
        }
        if (x == 2 || x == 4) {
            string = " ";
        }
        if (x == 3) {
            string = "/";
        }
        string = string + "(";
        string = string + print_torso(torso);
        string = string + ")";
        if (y == 1) {
            string = string + ">";
        }
        if (y == 2 || y == 4) {
            string = string + " ";
        }
        if (y == 3) {
            string = string + "\\";
        }
        string = string + "\n";
        return string;
    }

    string snowman(int code) {
        array<int,length> arr = {};
        for (int i = length-1; i >= 0; i--) {
            if (code % hex_base >= min&& code % hex_base <= max) {
                arr.at(i) = code % hex_base;
                code /= hex_base;
            } else {
                throw out_of_range{"Bad code"};
            }
        }
        if (code%hex_base!=0) {
            throw out_of_range{"Bad code"};
        }
        string string = print_hat(arr.at(hat));
        string = string + print3(arr.at(nose), arr.at(left_eye), arr.at(right_eye),arr.at(left_hand), arr.at(right_hand));
        string = string + print4(arr.at(left_hand), arr.at(right_hand), arr.at(torso));
        string = string + print_base(arr.at(base));
        return string;
    }
}