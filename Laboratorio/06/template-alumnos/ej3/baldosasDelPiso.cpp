int baldosasDelPiso(int M, int N, int B)
{
	int areaPiso = M * N;
	int areaBaldosa = B * B;
	int cantBaldosas = areaPiso / areaBaldosa;
	if (cantBaldosas * areaBaldosa < areaPiso)
		cantBaldosas++;
	return cantBaldosas;
}
