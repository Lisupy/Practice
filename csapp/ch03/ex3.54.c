int decode2(int x, int y, int z)
{
	int t = x - y;
	return (t>>15<<15)*(t^x);
}
