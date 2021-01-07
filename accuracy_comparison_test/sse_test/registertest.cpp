#include<iostream>
#include<emmintrin.h>
using namespace std;

int main()

{
    __m128d sse=_mm_setr_pd(2,4);
    __m128d sse2={2,4};
    

    __m128d addition= _mm_add_sd(sse,sse2); //only adds a[0], a[0]
    __m128d addition2= _mm_add_pd(sse,sse2); // adds a[0] to b[0] and a[1] to b[1]
     //addition=_mm_shuffle_pd(addition,addition,1); // shuffles a[0] with a[1]
     //addition=_mm_mul_pd(sse,sse2);
     __m128d compare=_mm_cmpeq_pd(sse,sse2);
     sse=_mm_shuffle_pd(addition,addition,1);

          
          if(compare[0]>-1 && compare[1])
          {

          }




    
    

            std::cout<<compare[0]<<" "<<compare[1]<<endl;
            std::cout<<sse[0]<<" "<<sse[1]<<endl;

            return 0;

}