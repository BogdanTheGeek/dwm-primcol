#include"stdlib.h"
#include"stdio.h"


float Min( float fR, float fG, float fB );
float Max( float fR, float fG, float fB);

void RGBToHSL( int R, int G, int B, int* h, int* s, int* l );


int main(int argc, char *argv[]){
	
	int r, g, b, h, s, l;
	
	if(argc < 2) {
		printf("Please input RGB hex code in this format : XXXXXX\n");
		return 1;
	}

	for(int i = 1; i<argc; ++i){
		char *hexrgb = argv[i];
		int rgb = (int)strtol(hexrgb, NULL, 16);

		r = (rgb >> 16) & 0x0000FF;
		g = (rgb >> 8) & 0x0000FF;
		b = rgb & 0x0000FF;

		RGBToHSL(r, g, b, &h, &s, &l);

	//	printf("%d %d %d\n", h, s, l);
		printf("%d %s\n", s + (int)(l*0.7), hexrgb );
	}

	return 0;
}


float Min( float fR, float fG, float fB ){
    float fMin = fR;

    if (fG < fMin){
        fMin = fG;
    }
    if (fB < fMin){
        fMin = fB;
    }
    return fMin;
}


float Max( float fR, float fG, float fB){
    float fMax = fR;
    
	if (fG > fMax){
        fMax = fG;
    }
    if (fB > fMax){
        fMax = fB;
    }
    return fMax;
}

void RGBToHSL( int R, int G, int B, int* h, int* s, int* l ){
    int H = *h;
    int S = *s;
    int L = *l;

    float fR = R / 255.0;
    float fG = G / 255.0;
    float fB = B / 255.0;

    float fCMin = Min(fR, fG, fB);
    float fCMax = Max(fR, fG, fB);

    L = 50 * (fCMin + fCMax);

    if (fCMin == fCMax){
        S = 0;
        H = 0;

		*s = S;
		*h = H;
		*l = L;

        return ;
    }
    else if (L < 50){
        S = 100 * (fCMax - fCMin) / (fCMax + fCMin);
    }
    else{
        S = 100 * (fCMax - fCMin) / (2.0 - fCMax - fCMin);
    }

    if (fCMax == fR){
        H = 60 * (fG - fB) / (fCMax - fCMin);
    }
    if (fCMax == fG){
        H = 60 * (fB - fR) / (fCMax - fCMin) + 120;
    }
    if (fCMax == fB){
        H = 60 * (fR - fG) / (fCMax - fCMin) + 240;
    }
    if (H < 0){
        H = H + 360;
    }
	*h = H;
	*s = S;
	*l = L;

}
