#include<bits/stdc++.h>
int main (){
    int max=0x3f3f3f3f,min=0,n,a,b,mid;
    std::cin>>n;
    while(n--){
        std::cin>>a>>b;
        mid=a/b;//最大炼k显然会出现到a/b恰好为k时，为了满足所有情况，就取所有的a/b取min
        max=std::min(mid,max);
        mid=a/(b+1)+1;//最小的k应该会出现一种情况，转化率差一点就让冶炼多了一块,那么b加上一个最小的一块，a/（b+1）求恰好冶炼多了一块的冶炼率，然后加1让它不满足这种情况
        min=std::max(min,mid);//此时就是次冶炼的最小的k，然后为了满足所有情况，对所有的取max
    }
    std::cout<<min<<' '<<max<<std::endl;
    return 0;
}