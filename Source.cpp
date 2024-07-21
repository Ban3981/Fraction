#include "Fraction.h"

                int main()
                {
                    using MathStuff::Fraction;

                    Fraction A(-3,7),B(8,-3);
                    std::cout<<A<<'+'<<B<<'='<<A+B<<std::endl;
                    std::cout<<A<<'-'<<B<<'='<<A-B<<std::endl;
                    std::cout<<(A<B)<<std::endl;
                    std::cout<<(A>B)<<std::endl;
                    std::cout<<(A==B)<<std::endl;
                    std::cout<<(A!=B)<<std::endl;
                    std::cout<<(A<=B)<<std::endl;
                    std::cout<<(A>=B)<<std::endl;

                    for(int i=1;i<=3;i++)
                    {
                        Fraction temp;
                        try
                        {
                            std::cin>>temp;
                        }
                        catch(const std::exception& ex)
                        {
                            std::cerr<<ex.what()<<std::endl;
                        }
                    }

                    return 0;
                }
