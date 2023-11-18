#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
typedef long long ll;

bool check(long double x, ll k, vector<ll>& a, vector<ll>& b) {
	/*


		(A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) = X

		(A[i1]+A[i2]+A[i3]+……+A[iK]) - X*(B[i1]+B[i2]+B[i3]+……+B[iK]) = 0

		(A[i1] - XB[i1]) + (A[i2] - XB[i2]) + …… + (A[iK] - X*B[iK]) = 0

		SUM OF TOP K ELEMENTS FROM THE PRIORITY QUEUE / SET SHOULD BE >= 0 (AS CLOSE AS POSSIBLE)


		mid = 2.42857
		-2.71429 2.71429
		2.428571

	*/

	set<long double> st;
	long double sumOfTopK_elements = 0.0;

	// cout << "extra set elements : " << nline;
	for (int i = 0; i < a.size(); ++i)
	{

		long double roundedNum = a[i] - (x * b[i]);
		roundedNum = round( roundedNum * 1e6) / 1e6; // round to 6 decimal places

		st.insert(roundedNum);

		if (st.size() > k) {
			// cout << *st.begin() << " ";
			st.erase(st.begin());
		}
	}
	// cout << nline;


	while (st.size())
	{
		long double currMax = *st.begin();
		// cout << *st.begin() << " ";
		st.erase(st.begin());
		sumOfTopK_elements += currMax;
	}
	// cout << nline;

	return sumOfTopK_elements >= 0.0d;
}



void solve() {

	ll n, k;
	cin >> n >> k;

	vector<ll> a(n), b(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	long double lo = 0.0, hi = (1e8 + 5) * 1.0, ans = 0.0;

	while (abs(lo - hi) > 1e-8)
	{
		long double mid = (lo + hi) / 2.0;
		// cout << "mid : " << mid << nline;

		if (check(mid, k, a, b)) {
			ans = mid;
			lo = mid;
		}
		else hi = mid;
	}

	cout << setprecision(10) << ans << nline;

}

int main() {

	int t;
	cin >> t;

	while (t--) {

		solve();
	}

	return 0;
}

/*

mid : 5e+007
extra set elements :
-2.5e+008
-2e+008 -1.5e+008
mid : 2.5e+007
extra set elements :
-1.25e+008
-1e+008 -7.5e+007
mid : 1.25e+007
extra set elements :
-6.25e+007
-5e+007 -3.75e+007
mid : 6.25e+006
extra set elements :
-3.125e+007
-2.5e+007 -1.875e+007
mid : 3.125e+006
extra set elements :
-1.5625e+007
-1.25e+007 -9.37499e+006
mid : 1.5625e+006
extra set elements :
-7.81249e+006
-6.24999e+006 -4.68749e+006
mid : 781250
extra set elements :
-3.90624e+006
-3.12499e+006 -2.34374e+006
mid : 390625
extra set elements :
-1.95312e+006
-1.56249e+006 -1.17186e+006
mid : 195312
extra set elements :
-976554
-781243 -585928
mid : 97656.2
extra set elements :
-488272
-390618 -292959
mid : 48828.1
extra set elements :
-244132
-195306 -146474
mid : 24414.1
extra set elements :
-122061
-97649.2 -73232.2
mid : 12207
extra set elements :
-61026.2
-48821.1 -36611.1
mid : 6103.52
extra set elements :
-30508.6
-24407.1 -18300.5
mid : 3051.76
extra set elements :
-15249.8
-12200 -9145.27
mid : 1525.88
extra set elements :
-7620.39
-6096.52 -4567.64
mid : 762.939
extra set elements :
-3805.7
-3044.76 -2278.82
mid : 381.47
extra set elements :
-1898.35
-1518.88 -1134.41
mid : 190.735
extra set elements :
-944.674
-755.939 -562.205
mid : 95.3674
extra set elements :
-467.837
-374.47 -276.102
mid : 47.6837
extra set elements :
-229.419
-183.735 -133.051
mid : 23.8419
extra set elements :
-110.209
-88.3674 -61.5256
mid : 11.9209
extra set elements :
-50.6046
-40.6837 -25.7628
mid : 5.96046
extra set elements :
-20.8023
-16.8419 -7.88139
mid : 2.98023
extra set elements :
-5.90116
-4.92093 1.0593
mid : 1.49012
extra set elements :
1.03954
1.54942 5.52965
mid : 2.23517
extra set elements :
-2.17587
-1.9407 3.29448
mid : 2.6077
extra set elements :
-4.03852
-3.43081 2.17689
mid : 2.42144
extra set elements :
-3.10719
-2.68575 2.73568
mid : 2.51457
extra set elements :
-3.57285
-3.05828 2.45629
mid : 2.468
extra set elements :
-3.34002
-2.87202 2.59599
mid : 2.44472
extra set elements :
-3.22361
-2.77889 2.66583
mid : 2.43308
extra set elements :
-3.1654
-2.73232 2.70076
mid : 2.42726
extra set elements :
-3.1363
-2.70904 2.71822
mid : 2.43017
extra set elements :
-3.15085
-2.72068 2.70949
mid : 2.42871
extra set elements :
-3.14357
-2.71486 2.71386
mid : 2.42799
extra set elements :
-3.13994
-2.71195 2.71604
mid : 2.42835
extra set elements :
-3.14175
-2.7134 2.71495
mid : 2.42853
extra set elements :
-3.14266
-2.71413 2.7144
mid : 2.42862
extra set elements :
-3.14312
-2.71449 2.71413
mid : 2.42858
extra set elements :
-3.14289
-2.71431 2.71427
mid : 2.42856
extra set elements :
-3.14278
-2.71422 2.71433
mid : 2.42857
extra set elements :
-3.14283
-2.71427 2.7143
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71428
mid : 2.42857
extra set elements :
-3.14285
-2.71428 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71428 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71428
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
mid : 2.42857
extra set elements :
-3.14286
-2.71429 2.71429
2.428571428
mid : 50000000
extra set elements :
-249999999 -249999997
-149999995 -99999998 -99999996
mid : 25000000
extra set elements :
-124999999 -124999997
-74999995 -49999998 -49999996
mid : 12500000
extra set elements :
-62499999 -62499997
-37499995 -24999998 -24999996
mid : 6250000
extra set elements :
-31249999 -31249997
-18749995 -12499998 -12499996
mid : 3125000
extra set elements :
-15624999 -15624997
-9374995 -6249998 -6249996
mid : 1562500
extra set elements :
-7812499 -7812497
-4687495 -3124998 -3124996
mid : 781250
extra set elements :
-3906249 -3906247
-2343745 -1562498 -1562496
mid : 390625
extra set elements :
-1953124 -1953122
-1171870 -781248 -781246
mid : 195312.5
extra set elements :
-976561.5 -976559.5
-585932.5 -390623 -390621
mid : 97656.25
extra set elements :
-488280.25 -488278.25
-292963.75 -195310.5 -195308.5
mid : 48828.125
extra set elements :
-244139.625 -244137.625
-146479.375 -97654.25 -97652.25
mid : 24414.0625
extra set elements :
-122069.3125 -122067.3125
-73237.1875 -48826.125 -48824.125
mid : 12207.03125
extra set elements :
-61034.15625 -61032.15625
-36616.09375 -24412.0625 -24410.0625
mid : 6103.515625
extra set elements :
-30516.57812 -30514.57812
-18305.54688 -12205.03125 -12203.03125
mid : 3051.757812
extra set elements :
-15257.78906 -15255.78906
-9150.273438 -6101.515625 -6099.515625
mid : 1525.878906
extra set elements :
-7628.394531 -7626.394531
-4572.636719 -3049.757812 -3047.757812
mid : 762.9394531
extra set elements :
-3813.697266 -3811.697266
-2283.818359 -1523.878906 -1521.878906
mid : 381.4697266
extra set elements :
-1906.348633 -1904.348633
-1139.40918 -760.9394531 -758.9394531
mid : 190.7348633
extra set elements :
-952.6743164 -950.6743164
-567.2045898 -379.4697266 -377.4697266
mid : 95.36743164
extra set elements :
-475.8371582 -473.8371582
-281.1022949 -188.7348633 -186.7348633
mid : 47.68371582
extra set elements :
-237.4185791 -235.4185791
-138.0511475 -93.36743164 -91.36743164
mid : 23.84185791
extra set elements :
-118.2092896 -116.2092896
-66.52557373 -45.68371582 -43.68371582
mid : 11.92092896
extra set elements :
-58.60464478 -56.60464478
-30.76278687 -21.84185791 -19.84185791
mid : 5.960464478
extra set elements :
-28.80232239 -26.80232239
-12.88139343 -9.920928955 -7.920928955
mid : 2.980232239
extra set elements :
-13.90116119 -11.90116119
-3.960464478 -3.940696716 -1.960464478
mid : 1.490116119
extra set elements :
-6.450580597 -4.450580597
-0.9802322388 0.5296516418 1.019767761
mid : 2.235174179
extra set elements :
-10.1758709 -8.175870895
-2.470348358 -1.705522537 -0.4703483582
mid : 1.862645149
extra set elements :
-8.313225746 -6.313225746
-1.725290298 -0.5879354477 0.2747097015
mid : 1.676380634
extra set elements :
-7.381903172 -5.381903172
-1.352761269 -0.02914190292 0.6472387314
mid : 1.583248377
extra set elements :
-6.916241884 -4.916241884
-1.166496754 0.2502548695 0.8335032463
mid : 1.536682248
extra set elements :
-6.683411241 -4.683411241
-1.073364496 0.3899532557 0.9266355038
mid : 1.559965312
extra set elements :
-6.799826562 -4.799826562
-1.119930625 0.3201040626 0.880069375
mid : 1.571606845
extra set elements :
-6.858034223 -4.858034223
-1.143213689 0.285179466 0.8567863107
mid : 1.565786079
extra set elements :
-6.828930393 -4.828930393
-1.131572157 0.3026417643 0.8684278429
mid : 1.568696462
extra set elements :
-6.843482308 -4.843482308
-1.137392923 0.2939106151 0.8626070768
mid : 1.570151653
extra set elements :
-6.850758266 -4.850758266
-1.140303306 0.2895450406 0.8596966937
mid : 1.570879249
extra set elements :
-6.854396245 -4.854396245
-1.141758498 0.2873622533 0.8582415022
mid : 1.571243047
extra set elements :
-6.856215234 -4.856215234
-1.142486094 0.2862708597 0.8575139064
mid : 1.571424946
extra set elements :
-6.857124729 -4.857124729
-1.142849891 0.2857251628 0.8571501086
mid : 1.571515895
extra set elements :
-6.857579476 -4.857579476
-1.14303179 0.2854523144 0.8569682096
mid : 1.57147042
extra set elements :
-6.857352102 -4.857352102
-1.142940841 0.2855887386 0.8570591591
mid : 1.571447683
extra set elements :
-6.857238415 -4.857238415
-1.142895366 0.2856569507 0.8571046338
mid : 1.571436314
extra set elements :
-6.857181572 -4.857181572
-1.142872629 0.2856910568 0.8571273712
mid : 1.57143063
extra set elements :
-6.85715315 -4.85715315
-1.14286126 0.2857081098 0.8571387399
mid : 1.571427788
extra set elements :
-6.857138939 -4.857138939
-1.142855576 0.2857166363 0.8571444242
mid : 1.571429209
extra set elements :
-6.857146045 -4.857146045
-1.142858418 0.2857123731 0.857141582
mid : 1.571428498
extra set elements :
-6.857142492 -4.857142492
-1.142856997 0.2857145047 0.8571430031
mid : 1.571428854
extra set elements :
-6.857144269 -4.857144269
-1.142857707 0.2857134389 0.8571422926
mid : 1.571428676
extra set elements :
-6.85714338 -4.85714338
-1.142857352 0.2857139718 0.8571426479
mid : 1.571428587
extra set elements :
-6.857142936 -4.857142936
-1.142857175 0.2857142382 0.8571428255
mid : 1.571428543
extra set elements :
-6.857142714 -4.857142714
-1.142857086 0.2857143715 0.8571429143
mid : 1.571428565
extra set elements :
-6.857142825 -4.857142825
-1.14285713 0.2857143048 0.8571428699
mid : 1.571428576
extra set elements :
-6.857142881 -4.857142881
-1.142857152 0.2857142715 0.8571428477
mid : 1.571428571
extra set elements :
-6.857142853 -4.857142853
-1.142857141 0.2857142882 0.8571428588
mid : 1.571428573
extra set elements :
-6.857142867 -4.857142867
-1.142857147 0.2857142799 0.8571428532
mid : 1.571428572
extra set elements :
-6.85714286 -4.85714286
-1.142857144 0.285714284 0.857142856
mid : 1.571428571
extra set elements :
-6.857142856 -4.857142856
-1.142857143 0.2857142861 0.8571428574
1.571428571
mid : 50000000
extra set elements :

-49999999
mid : 25000000
extra set elements :

-24999999
mid : 12500000
extra set elements :

-12499999
mid : 6250000
extra set elements :

-6249999
mid : 3125000
extra set elements :

-3124999
mid : 1562500
extra set elements :

-1562499
mid : 781250
extra set elements :

-781249
mid : 390625
extra set elements :

-390624
mid : 195312.5
extra set elements :

-195311.5
mid : 97656.25
extra set elements :

-97655.25
mid : 48828.125
extra set elements :

-48827.125
mid : 24414.0625
extra set elements :

-24413.0625
mid : 12207.03125
extra set elements :

-12206.03125
mid : 6103.515625
extra set elements :

-6102.515625
mid : 3051.757812
extra set elements :

-3050.757812
mid : 1525.878906
extra set elements :

-1524.878906
mid : 762.9394531
extra set elements :

-761.9394531
mid : 381.4697266
extra set elements :

-380.4697266
mid : 190.7348633
extra set elements :

-189.7348633
mid : 95.36743164
extra set elements :

-94.36743164
mid : 47.68371582
extra set elements :

-46.68371582
mid : 23.84185791
extra set elements :

-22.84185791
mid : 11.92092896
extra set elements :

-10.92092896
mid : 5.960464478
extra set elements :

-4.960464478
mid : 2.980232239
extra set elements :

-1.980232239
mid : 1.490116119
extra set elements :

-0.4901161194
mid : 0.7450580597
extra set elements :

0.2549419403
mid : 1.11758709
extra set elements :

-0.1175870895
mid : 0.9313225746
extra set elements :

0.06867742538
mid : 1.024454832
extra set elements :

-0.02445483208
mid : 0.9778887033
extra set elements :

0.02211129665
mid : 1.001171768
extra set elements :

-0.001171767712
mid : 0.9895302355
extra set elements :

0.01046976447
mid : 0.9953510016
extra set elements :

0.00464899838
mid : 0.9982613847
extra set elements :

0.001738615334
mid : 0.9997165762
extra set elements :

0.0002834238112
mid : 1.000444172
extra set elements :

-0.0004441719502
mid : 1.000080374
extra set elements :

-8.037406951e-005
mid : 0.9998984751
extra set elements :

0.0001015248708
mid : 0.9999894246
extra set elements :

1.057540067e-005
mid : 1.000034899
extra set elements :

-3.489933442e-005
mid : 1.000012162
extra set elements :

-1.216196688e-005
mid : 1.000000793
extra set elements :

-7.932831068e-007
mid : 0.9999951089
extra set elements :

4.891058779e-006
mid : 0.9999979511
extra set elements :

2.048887836e-006
mid : 0.9999993722
extra set elements :

6.278023648e-007
mid : 1.000000083
extra set elements :

-8.2740371e-008
mid : 0.9999997275
extra set elements :

2.725309969e-007
mid : 0.9999999051
extra set elements :

9.489531294e-008
mid : 0.9999999939
extra set elements :

6.077470971e-009
mid : 1.000000038
extra set elements :

-3.833145001e-008
mid : 1.000000016
extra set elements :

-1.612698952e-008
mid : 1.000000005
extra set elements :

-5.024759275e-009
mid : 0.9999999995
extra set elements :

5.263558478e-010
mid : 1.000000002
extra set elements :

-2.249201714e-009
mid : 1.000000001
extra set elements :

-8.61422933e-010
mid : 1
extra set elements :

-1.675335426e-010
0.9999999995

*/