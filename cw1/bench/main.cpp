#include <nanobench.h>
#include <vmlib/small_matrix.hpp>

#include <string>

template< std::size_t tN >
void test_matrix()
{
	SmallMat<tN,tN,float> a{};
	SmallMat<tN,tN,float> c{};

	// Prepare the matrices before timing.
	for( std::size_t i = 0; i < tN; ++i )
	{
		for( std::size_t j = 0; j < tN; ++j )
		{
			a[i,j] = float((i + j) % 5) / 10.f;
			c[i,j] = float((i + j) % 7) / 10.f;
		}

		a[i,i] += float(tN);
		c[i,i] += float(tN);
	}

	ankerl::nanobench::Bench b;
	std::string size = std::to_string(tN);

	b.warmup( 10 );

	b.run( "inverse " + size, [&] {
		ankerl::nanobench::doNotOptimizeAway( a );

		auto result = invert( a );

		ankerl::nanobench::doNotOptimizeAway( result );
	} );

	b.run( "multiply " + size, [&] {
		ankerl::nanobench::doNotOptimizeAway( a );
		ankerl::nanobench::doNotOptimizeAway( c );

		auto result = a * c;

		ankerl::nanobench::doNotOptimizeAway( result );
	} );
}

int main()
{
	test_matrix<2>();
	test_matrix<3>();
	test_matrix<4>();
	test_matrix<8>();
	test_matrix<16>();
	test_matrix<32>();
	test_matrix<64>();
	test_matrix<100>();

	return 0;
}