#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int testcases;
	cin >> testcases;
	while (testcases--) {
		int n, k;
		cin >> n >> k;
		int arr[n], brr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
			cin >> brr[i];
		ld low = 0.0, high = 1e8;
		ld ans = 0.0;
		while (abs(low - high) > 1e-9) {
			ld mid = (low + high) / 2.0;


			priority_queue <ld, vector<ld>, greater<ld>> pq;
			for (int i = 0; i < n; i++) {
				pq.push(arr[i] - mid * brr[i]);
				if (pq.size() > k) {
					pq.pop();
				}
			}

			ld s = 0.0;
			while (pq.size()) {

				s += pq.top();
				pq.pop();
			}

			if (s >= 0.0)
				ans = mid, low = mid;
			else
				high = mid;
		}
		cout << fixed << setprecision(6) << ans << "\n";
	}
}

/*



mid = 5e+007
extra pq.top()-2.5e+008
-2e+008 -1.5e+008
mid = 2.5e+007
extra pq.top()-1.25e+008
-1e+008 -7.5e+007
mid = 1.25e+007
extra pq.top()-6.25e+007
-5e+007 -3.75e+007
mid = 6.25e+006
extra pq.top()-3.125e+007
-2.5e+007 -1.875e+007
mid = 3.125e+006
extra pq.top()-1.5625e+007
-1.25e+007 -9.37499e+006
mid = 1.5625e+006
extra pq.top()-7.81249e+006
-6.24999e+006 -4.68749e+006
mid = 781250
extra pq.top()-3.90624e+006
-3.12499e+006 -2.34374e+006
mid = 390625
extra pq.top()-1.95312e+006
-1.56249e+006 -1.17186e+006
mid = 195312
extra pq.top()-976554
-781243 -585928
mid = 97656.2
extra pq.top()-488272
-390618 -292959
mid = 48828.1
extra pq.top()-244132
-195306 -146474
mid = 24414.1
extra pq.top()-122061
-97649.2 -73232.2
mid = 12207
extra pq.top()-61026.2
-48821.1 -36611.1
mid = 6103.52
extra pq.top()-30508.6
-24407.1 -18300.5
mid = 3051.76
extra pq.top()-15249.8
-12200 -9145.27
mid = 1525.88
extra pq.top()-7620.39
-6096.52 -4567.64
mid = 762.939
extra pq.top()-3805.7
-3044.76 -2278.82
mid = 381.47
extra pq.top()-1898.35
-1518.88 -1134.41
mid = 190.735
extra pq.top()-944.674
-755.939 -562.205
mid = 95.3674
extra pq.top()-467.837
-374.47 -276.102
mid = 47.6837
extra pq.top()-229.419
-183.735 -133.051
mid = 23.8419
extra pq.top()-110.209
-88.3674 -61.5256
mid = 11.9209
extra pq.top()-50.6046
-40.6837 -25.7628
mid = 5.96046
extra pq.top()-20.8023
-16.8419 -7.88139
mid = 2.98023
extra pq.top()-5.90116
-4.92093 1.0593
mid = 1.49012
extra pq.top()1.03954
1.54942 5.52965
mid =
extra pq.top()-2.17587
-1.9407 3.29448
mid = 2.6077
extra pq.top()-4.03852
-3.43081 2.17689
mid = 2.42144
extra pq.top()-3.10719
-2.68575 2.73568
mid = 2.51457
extra pq.top()-3.57285
-3.05828 2.45629
mid = 2.468
extra pq.top()-3.34002
-2.87202 2.59599
mid = 2.44472
extra pq.top()-3.22361
-2.77889 2.66583
mid = 2.43308
extra pq.top()-3.1654
-2.73232 2.70076
mid = 2.42726
extra pq.top()-3.1363
-2.70904 2.71822
mid = 2.43017
extra pq.top()-3.15085
-2.72068 2.70949
mid = 2.42871
extra pq.top()-3.14357
-2.71486 2.71386
mid = 2.42799
extra pq.top()-3.13994
-2.71195 2.71604
mid = 2.42835
extra pq.top()-3.14175
-2.7134 2.71495
mid = 2.42853
extra pq.top()-3.14266
-2.71413 2.7144
mid = 2.42862
extra pq.top()-3.14312
-2.71449 2.71413
mid = 2.42858
extra pq.top()-3.14289
-2.71431 2.71427
mid = 2.42856
extra pq.top()-3.14278
-2.71422 2.71433
mid = 2.42857
extra pq.top()-3.14283
-2.71427 2.7143
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71428
mid = 2.42857
extra pq.top()-3.14285
-2.71428 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71428 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71428
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
mid = 2.42857
extra pq.top()-3.14286
-2.71429 2.71429
2.428571
mid = 50000000.000000
extra pq.top()-249999999.000000 extra pq.top()-149999995.000000 extra pq.top()-249999997.000000 extra pq.top()-99999998.000000 extra pq.top()-149999995.000000
-99999998.000000 -99999996.000000 -99999996.000000
mid = 25000000.000000
extra pq.top()-124999999.000000 extra pq.top()-74999995.000000 extra pq.top()-124999997.000000 extra pq.top()-49999998.000000 extra pq.top()-74999995.000000
-49999998.000000 -49999996.000000 -49999996.000000
mid = 12500000.000000
extra pq.top()-62499999.000000 extra pq.top()-37499995.000000 extra pq.top()-62499997.000000 extra pq.top()-24999998.000000 extra pq.top()-37499995.000000
-24999998.000000 -24999996.000000 -24999996.000000
mid = 6250000.000000
extra pq.top()-31249999.000000 extra pq.top()-18749995.000000 extra pq.top()-31249997.000000 extra pq.top()-12499998.000000 extra pq.top()-18749995.000000
-12499998.000000 -12499996.000000 -12499996.000000
mid = 3125000.000000
extra pq.top()-15624999.000000 extra pq.top()-9374995.000000 extra pq.top()-15624997.000000 extra pq.top()-6249998.000000 extra pq.top()-9374995.000000
-6249998.000000 -6249996.000000 -6249996.000000
mid = 1562500.000000
extra pq.top()-7812499.000000 extra pq.top()-4687495.000000 extra pq.top()-7812497.000000 extra pq.top()-3124998.000000 extra pq.top()-4687495.000000
-3124998.000000 -3124996.000000 -3124996.000000
mid = 781250.000000
extra pq.top()-3906249.000000 extra pq.top()-2343745.000000 extra pq.top()-3906247.000000 extra pq.top()-1562498.000000 extra pq.top()-2343745.000000
-1562498.000000 -1562496.000000 -1562496.000000
mid = 390625.000000
extra pq.top()-1953124.000000 extra pq.top()-1171870.000000 extra pq.top()-1953122.000000 extra pq.top()-781248.000000 extra pq.top()-1171870.000000
-781248.000000 -781246.000000 -781246.000000
mid = 195312.500000
extra pq.top()-976561.500000 extra pq.top()-585932.500000 extra pq.top()-976559.500000 extra pq.top()-390623.000000 extra pq.top()-585932.500000
-390623.000000 -390621.000000 -390621.000000
mid = 97656.250000
extra pq.top()-488280.250000 extra pq.top()-292963.750000 extra pq.top()-488278.250000 extra pq.top()-195310.500000 extra pq.top()-292963.750000
-195310.500000 -195308.500000 -195308.500000
mid = 48828.125000
extra pq.top()-244139.625000 extra pq.top()-146479.375000 extra pq.top()-244137.625000 extra pq.top()-97654.250000 extra pq.top()-146479.375000
-97654.250000 -97652.250000 -97652.250000
mid = 24414.062500
extra pq.top()-122069.312500 extra pq.top()-73237.187500 extra pq.top()-122067.312500 extra pq.top()-48826.125000 extra pq.top()-73237.187500
-48826.125000 -48824.125000 -48824.125000
mid = 12207.031250
extra pq.top()-61034.156250 extra pq.top()-36616.093750 extra pq.top()-61032.156250 extra pq.top()-24412.062500 extra pq.top()-36616.093750
-24412.062500 -24410.062500 -24410.062500
mid = 6103.515625
extra pq.top()-30516.578125 extra pq.top()-18305.546875 extra pq.top()-30514.578125 extra pq.top()-12205.031250 extra pq.top()-18305.546875
-12205.031250 -12203.031250 -12203.031250
mid = 3051.757812
extra pq.top()-15257.789062 extra pq.top()-9150.273438 extra pq.top()-15255.789062 extra pq.top()-6101.515625 extra pq.top()-9150.273438
-6101.515625 -6099.515625 -6099.515625
mid = 1525.878906
extra pq.top()-7628.394531 extra pq.top()-4572.636719 extra pq.top()-7626.394531 extra pq.top()-3049.757812 extra pq.top()-4572.636719
-3049.757812 -3047.757812 -3047.757812
mid = 762.939453
extra pq.top()-3813.697266 extra pq.top()-2283.818359 extra pq.top()-3811.697266 extra pq.top()-1523.878906 extra pq.top()-2283.818359
-1523.878906 -1521.878906 -1521.878906
mid = 381.469727
extra pq.top()-1906.348633 extra pq.top()-1139.409180 extra pq.top()-1904.348633 extra pq.top()-760.939453 extra pq.top()-1139.409180
-760.939453 -758.939453 -758.939453
mid = 190.734863
extra pq.top()-952.674316 extra pq.top()-567.204590 extra pq.top()-950.674316 extra pq.top()-379.469727 extra pq.top()-567.204590
-379.469727 -377.469727 -377.469727
mid = 95.367432
extra pq.top()-475.837158 extra pq.top()-281.102295 extra pq.top()-473.837158 extra pq.top()-188.734863 extra pq.top()-281.102295
-188.734863 -186.734863 -186.734863
mid = 47.683716
extra pq.top()-237.418579 extra pq.top()-138.051147 extra pq.top()-235.418579 extra pq.top()-93.367432 extra pq.top()-138.051147
-93.367432 -91.367432 -91.367432
mid = 23.841858
extra pq.top()-118.209290 extra pq.top()-66.525574 extra pq.top()-116.209290 extra pq.top()-45.683716 extra pq.top()-66.525574
-45.683716 -43.683716 -43.683716
mid = 11.920929
extra pq.top()-58.604645 extra pq.top()-30.762787 extra pq.top()-56.604645 extra pq.top()-21.841858 extra pq.top()-30.762787
-21.841858 -19.841858 -19.841858
mid = 5.960464
extra pq.top()-28.802322 extra pq.top()-12.881393 extra pq.top()-26.802322 extra pq.top()-9.920929 extra pq.top()-12.881393
-9.920929 -7.920929 -7.920929
mid = 2.980232
extra pq.top()-13.901161 extra pq.top()-3.960464 extra pq.top()-11.901161 extra pq.top()-3.960464 extra pq.top()-3.940697
-3.940697 -1.960464 -1.960464
mid = 1.490116
extra pq.top()-6.450581 extra pq.top()-0.980232 extra pq.top()-4.450581 extra pq.top()-0.980232 extra pq.top()0.529652
0.529652 1.019768 1.019768
mid = 2.235174
extra pq.top()-10.175871 extra pq.top()-2.470348 extra pq.top()-8.175871 extra pq.top()-2.470348 extra pq.top()-1.705523
-1.705523 -0.470348 -0.470348
mid = 1.862645
extra pq.top()-8.313226 extra pq.top()-1.725290 extra pq.top()-6.313226 extra pq.top()-1.725290 extra pq.top()-0.587935
-0.587935 0.274710 0.274710
mid = 1.676381
extra pq.top()-7.381903 extra pq.top()-1.352761 extra pq.top()-5.381903 extra pq.top()-1.352761 extra pq.top()-0.029142
-0.029142 0.647239 0.647239
mid = 1.769513
extra pq.top()-7.847564 extra pq.top()-1.539026 extra pq.top()-5.847564 extra pq.top()-1.539026 extra pq.top()-0.308539
-0.308539 0.460974 0.460974
mid = 1.816079
extra pq.top()-8.080395 extra pq.top()-1.632158 extra pq.top()-6.080395 extra pq.top()-1.632158 extra pq.top()-0.448237
-0.448237 0.367842 0.367842
mid = 1.839362
extra pq.top()-8.196810 extra pq.top()-1.678724 extra pq.top()-6.196810 extra pq.top()-1.678724 extra pq.top()-0.518086
-0.518086 0.321276 0.321276
mid = 1.851004
extra pq.top()-8.255018 extra pq.top()-1.702007 extra pq.top()-6.255018 extra pq.top()-1.702007 extra pq.top()-0.553011
-0.553011 0.297993 0.297993
mid = 1.856824
extra pq.top()-8.284122 extra pq.top()-1.713649 extra pq.top()-6.284122 extra pq.top()-1.713649 extra pq.top()-0.570473
-0.570473 0.286351 0.286351
mid = 1.859735
extra pq.top()-8.298674 extra pq.top()-1.719470 extra pq.top()-6.298674 extra pq.top()-1.719470 extra pq.top()-0.579204
-0.579204 0.280530 0.280530
mid = 1.858280
extra pq.top()-8.291398 extra pq.top()-1.716559 extra pq.top()-6.291398 extra pq.top()-1.716559 extra pq.top()-0.574839
-0.574839 0.283441 0.283441
mid = 1.857552
extra pq.top()-8.287760 extra pq.top()-1.715104 extra pq.top()-6.287760 extra pq.top()-1.715104 extra pq.top()-0.572656
-0.572656 0.284896 0.284896
mid = 1.857188
extra pq.top()-8.285941 extra pq.top()-1.714376 extra pq.top()-6.285941 extra pq.top()-1.714376 extra pq.top()-0.571565
-0.571565 0.285624 0.285624
mid = 1.857006
extra pq.top()-8.285031 extra pq.top()-1.714013 extra pq.top()-6.285031 extra pq.top()-1.714013 extra pq.top()-0.571019
-0.571019 0.285987 0.285987
mid = 1.857097
extra pq.top()-8.285486 extra pq.top()-1.714194 extra pq.top()-6.285486 extra pq.top()-1.714194 extra pq.top()-0.571292
-0.571292 0.285806 0.285806
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714285 extra pq.top()-6.285714 extra pq.top()-1.714285 extra pq.top()-0.571428
-0.571428 0.285715 0.285715
mid = 1.857165
extra pq.top()-8.285827 extra pq.top()-1.714331 extra pq.top()-6.285827 extra pq.top()-1.714331 extra pq.top()-0.571496
-0.571496 0.285669 0.285669
mid = 1.857154
extra pq.top()-8.285770 extra pq.top()-1.714308 extra pq.top()-6.285770 extra pq.top()-1.714308 extra pq.top()-0.571462
-0.571462 0.285692 0.285692
mid = 1.857148
extra pq.top()-8.285742 extra pq.top()-1.714297 extra pq.top()-6.285742 extra pq.top()-1.714297 extra pq.top()-0.571445
-0.571445 0.285703 0.285703
mid = 1.857146
extra pq.top()-8.285728 extra pq.top()-1.714291 extra pq.top()-6.285728 extra pq.top()-1.714291 extra pq.top()-0.571437
-0.571437 0.285709 0.285709
mid = 1.857144
extra pq.top()-8.285721 extra pq.top()-1.714288 extra pq.top()-6.285721 extra pq.top()-1.714288 extra pq.top()-0.571432
-0.571432 0.285712 0.285712
mid = 1.857143
extra pq.top()-8.285717 extra pq.top()-1.714287 extra pq.top()-6.285717 extra pq.top()-1.714287 extra pq.top()-0.571430
-0.571430 0.285713 0.285713
mid = 1.857143
extra pq.top()-8.285715 extra pq.top()-1.714286 extra pq.top()-6.285715 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571428
-0.571428 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
mid = 1.857143
extra pq.top()-8.285714 extra pq.top()-1.714286 extra pq.top()-6.285714 extra pq.top()-1.714286 extra pq.top()-0.571429
-0.571429 0.285714 0.285714
1.857143
mid = 50000000.000000

-49999999.000000
mid = 25000000.000000

-24999999.000000
mid = 12500000.000000

-12499999.000000
mid = 6250000.000000

-6249999.000000
mid = 3125000.000000

-3124999.000000
mid = 1562500.000000

-1562499.000000
mid = 781250.000000

-781249.000000
mid = 390625.000000

-390624.000000
mid = 195312.500000

-195311.500000
mid = 97656.250000

-97655.250000
mid = 48828.125000

-48827.125000
mid = 24414.062500

-24413.062500
mid = 12207.031250

-12206.031250
mid = 6103.515625

-6102.515625
mid = 3051.757812

-3050.757812
mid = 1525.878906

-1524.878906
mid = 762.939453

-761.939453
mid = 381.469727

-380.469727
mid = 190.734863

-189.734863
mid = 95.367432

-94.367432
mid = 47.683716

-46.683716
mid = 23.841858

-22.841858
mid = 11.920929

-10.920929
mid = 5.960464

-4.960464
mid = 2.980232

-1.980232
mid = 1.490116

-0.490116
mid = 0.745058

0.254942
mid = 1.117587

-0.117587
mid = 0.931323

0.068677
mid = 1.024455

-0.024455
mid = 0.977889

0.022111
mid = 1.001172

-0.001172
mid = 0.989530

0.010470
mid = 0.995351

0.004649
mid = 0.998261

0.001739
mid = 0.999717

0.000283
mid = 1.000444

-0.000444
mid = 1.000080

-0.000080
mid = 0.999898

0.000102
mid = 0.999989

0.000011
mid = 1.000035

-0.000035
mid = 1.000012

-0.000012
mid = 1.000001

-0.000001
mid = 0.999995

0.000005
mid = 0.999998

0.000002
mid = 0.999999

0.000001
mid = 1.000000

-0.000000
mid = 1.000000

0.000000
mid = 1.000000

0.000000
mid = 1.000000

0.000000
mid = 1.000000

-0.000000
mid = 1.000000

-0.000000
mid = 1.000000

-0.000000
mid = 1.000000

0.000000
mid = 1.000000

-0.000000
mid = 1.000000

-0.000000
mid = 1.000000

-0.000000
1.000000

*/