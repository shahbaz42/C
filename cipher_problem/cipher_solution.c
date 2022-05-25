# include <stdio.h>
# include <string.h>

// function to convert desimal to bitsize bit binary
void bin(int n, int bitsize, char *b)
{
    int i, d;
    for (i = 0; i < bitsize; i++)
    {
        d = n >> (bitsize - i - 1);
        d &= 1;
        b[i] = d + '0';
    }
    b[bitsize] = '\0';
}

// function to convert bitsize bit binary to desimal
int dec(char *b, int bitsize)
{   
    int i=0, j=0, n = 0;
    char result[bitsize];
    
    // if length of binary is not equal to bitsize add 0 to the beginning
    for(i =0; i< bitsize; i++){
        if(i < bitsize-strlen(b)){
            result[i] = '0';
        }
        else{
            result[i] = b[j];
            j++;
        }
    }
    result[bitsize] = '\0';

    i = 0;
    for (i = 0; i < bitsize; i++)
    {
        if (result[i] == '1')
            n += (1 << (bitsize - i - 1));
    }
    return n;
} 

// function to iterate through text and generate intermediate text
void generate_intermediate(char *text, char *intermediate, int bin_bitsize){
    int i = 0;
    char binary[bin_bitsize + 1];
    for (i = 0; i < strlen(text); i++){
        bin(text[i], bin_bitsize, binary);
        strcat(intermediate, binary);
    }
}

// function to get an array from intermediate text
int get_intermediate_array(int *intermediate_array, char *intermediate, int bin_bitsize){
    int i = 0;
    int j = 0;
    char binary[bin_bitsize + 1];
    
    while(i < strlen(intermediate)){
        strncpy(binary, &intermediate[i], bin_bitsize);
        binary[bin_bitsize] = '\0';
        intermediate_array[j] = dec(binary, bin_bitsize);
        i += bin_bitsize;
        j++;
    }
    // Note: the last element of the array is not used, because it might 
    // contain incorrect value when the length og intermediete text is
    // not divisible by the bitsize of the binary number
    return j;
}

// function to generate cipher text
void generate_cipher(int *intermediate_array, int size){    
    char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-";
    int i = 0;
    for (i = 0; i < size; i++){
        printf("%c", key[intermediate_array[i]]);
    }
}

int main(){
    int MAX_SIZE = 1000;
    int desimal, bin_bitsize = 8, bin_group_bitsize = 6;
    
    char text[MAX_SIZE];
    char intermediate[MAX_SIZE]; intermediate[0] = '\0';
    int intermediate_array[MAX_SIZE];

    int int_arr_size;

    printf("Input text :");
    scanf("%[^\n]", text);

    // generate the intermediate text
    generate_intermediate(text, intermediate, bin_bitsize);
    //printf("intermediate = %s\n", intermediate);

    // generate intermediate array
    int_arr_size = get_intermediate_array(intermediate_array, intermediate, bin_group_bitsize);
    // printf("intermediate array = ");
    // for (int i = 0; i < int_arr_size; i++){
    //     printf("%d ", intermediate_array[i]);
    // }

    // generate cipher text
    generate_cipher(intermediate_array, int_arr_size);
    printf("\n");
}