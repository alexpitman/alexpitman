// Dca' = min(Sca.Da, Dca.Sa) + Sca.(1 - Da) + Dca.(1 - Sa)
// Da'  = Sa + Da - Sa.Da 
vec4 composite(vec4 src, vec4 dst)
{
    vec4 result;
    result.rgb = min(src.rgb * dst.a, dst.rgb * src.a) + src.rgb * (1.0 - dst.a) + dst.rgb * (1.0 - src.a);
    result.a = src.a + dst.a - src.a * dst.a;
    return result;
}
