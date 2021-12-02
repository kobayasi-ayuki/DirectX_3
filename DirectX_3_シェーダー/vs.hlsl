// 頂点シェーダ入力構造体
struct VS_INPUT
{
	float3 position     : POSITION;  // 頂点座標
	float3 sub_position : POSITION1; // 補助座標
	float3 normal       : NORMAL0;   // 法線
	float3 tangent      : TANGENT0;  // 接線
	float3 binormal     : BINORMAL0; // 従法線
	float2 texcoord     : TEXCOORD0; // テクスチャuv座標
	float texcoord2     : TEXCOORD1; // テクスチャv座標2
	float4 diffuse      : COLOR0;    // ディフィーズカラー
	float4 specular     : COLOR1;    // スペキュラカラー
};

// 頂点シェーダの出力
struct VS_OUTPUT
{
	float4 diffuse  : COLOR0;		// ディフィーズカラー
	float2 texcoord : TEXCOOD0;		// テクスチャuv座標
	float4 position : SV_POSITION;	// 座標
};

VS_OUTPUT main(VS_INPUT Input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;

	// 頂点座標を出力
	output.position = float4(Input.position, 1.0f);

	// ディフィーズカラーを出力
	output.diffuse = Input.diffuse;

	// uv座標を出力
	output.texcoord = Input.texcoord;

	return output;
}
