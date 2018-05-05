
//http://blog.michaelschmatz.com/2016/04/11/how-to-write-a-bloom-filter-cpp/
//by

#include "MurmurHash3.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include<array>



// bloom filter implementation


class BloomFilter {
private:
	uint8_t num_hashFunctions;
  std::vector<bool>numberOfBits ;


public:

	BloomFilter(uint64_t size_Cells, uint8_t num_funcs) : numberOfBits(size_Cells), num_hashFunctions(num_funcs) {}

		std::array<uint64_t, 2>  hash(uint8_t *data,std::size_t len)
		{
				std::array<uint64_t, 2> hashValue;
				MurmurHash3_x64_128(data, len, 0, hashValue.data());

				return hashValue;
			}
			inline uint64_t nthHash(uint8_t n,uint64_t hashA,uint64_t hashB,uint64_t filterSize)
			{
					return (hashA + n * hashB) % filterSize;
			}


				void add(uint8_t*data, std::size_t len)
				 {
					auto hashValues = hash(data, len);

					for (int n = 0; n < num_hashFunctions; n++) {
						numberOfBits[nthHash(n, hashValues[0], hashValues[1], numberOfBits.size())] = true;
					}
				}

				bool search( uint8_t  *data, std::size_t len)  {
					auto hashValues = hash(data, len);

					for (int n = 0; n < num_hashFunctions; n++) {
						if (!numberOfBits[nthHash(n, hashValues[0], hashValues[1], numberOfBits.size())]) {
							return false;
						}
					}

					return true;
				}


			};



				int main ()
				{
					return 0 ;

			}
