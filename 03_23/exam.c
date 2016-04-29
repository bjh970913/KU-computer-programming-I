#include <stdio.h>

int sex(int i){
    if(i<=1){
        printf("Yes\n");
        return 1;
    }
    else{
        printf("No\n");
        return i*sex(i-1);
    }
}

int main(int argc, char const *argv[])
{
    for(int i=1;i<=4;i++){
        printf("result: %d\n", sex(i));
    }
    return 0;
}