//The function is sent the inputChar (from the inputStringToMace() function)
//Checks the "Current character" against this case statement, and returns the MACE equivelant.

char* getMaceChar(char inputChar) {
  switch (inputChar) {
    case 'a': return mace_a;
    case 'b': return mace_b;
    case 'c': return mace_c;
    case 'd': return mace_d;
    case 'e': return mace_e;
    case 'f': return mace_f;
    case 'g': return mace_g;
    case 'h': return mace_h;
    case 'i': return mace_i;
    case 'j': return mace_j;
    case 'k': return mace_k;
    case 'l': return mace_l;
    case 'm': return mace_m;
    case 'n': return mace_n;
    case 'o': return mace_o;
    case 'p': return mace_p;
    case 'q': return mace_q;
    case 'r': return mace_r;
    case 's': return mace_s;
    case 't': return mace_t;
    case 'u': return mace_u;
    case 'v': return mace_v;
    case 'w': return mace_w;
    case 'x': return mace_x;
    case 'y': return mace_y;
    case 'z': return mace_z;
    case '1': return mace_1;
    case '2': return mace_2;
    case '3': return mace_3;
    case '4': return mace_4;
    case '5': return mace_5;
    case '6': return mace_6;
    case '7': return mace_7;
    case '8': return mace_8;
    case '9': return mace_9;
    case '0': return mace_0;
    case ' ': return mace_space;
    case '.': return mace_fullstop;
    case ',': return mace_comma;
    case 39 : return mace_apostraphe;    //ASCII code for Apostrophe
    case '?': return mace_question;
    case '!': return mace_exclamation;
    case '+': return mace_plus;
    case '-': return mace_minus;
    case '/': return mace_divide;
    case '*': return mace_multiply;
    case '=': return mace_equals;
    default: return mace_error;
  }
}
