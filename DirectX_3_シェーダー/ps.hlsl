Texture2D g_Texture : register(t0);// �e�N�X�`��
SamplerState g_Sampler : register(s0);// �e�N�X�`���T���v���[

float4 main(float2 uv : TEXCOORD0) : SV_TARGET
{
	float4 color;
	color.rbg = 1.0f;
	color.a = 1.0f;
	//color.rg = 0.5f;
	//color.r = 1.0f;
	//color.b = 1.0f;
	//color.g = 1.0f;

	// �e�N�X�`���J���[�̒��o
	float4 tex_color = g_Texture.Sample(g_Sampler, uv);

	// ���_�J���[�����̂܂܏o��
	return tex_color;
}