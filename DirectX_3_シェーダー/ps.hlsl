Texture2D g_Texture : register(t0);// テクスチャ
SamplerState g_Sampler : register(s0);// テクスチャサンプラー

float4 main(float2 uv : TEXCOORD0) : SV_TARGET
{
	float4 color;
	color.rbg = 1.0f;
	color.a = 1.0f;
	//color.rg = 0.5f;
	//color.r = 1.0f;
	//color.b = 1.0f;
	//color.g = 1.0f;

	// テクスチャカラーの抽出
	float4 tex_color = g_Texture.Sample(g_Sampler, uv);

	// 頂点カラーをそのまま出力
	return tex_color;
}