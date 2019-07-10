//2.1-3：
int Linear_Find(int a[],int length,int key){
    for(int i = 0;i < length;i++){
        if(a[i] == key)
            return i;       
    }
    return -1;
}

int main(){
    int a[9] = {5,2,4,6,1,3};
    int index = Linear_Find(a,6,2);
    return 0;
}