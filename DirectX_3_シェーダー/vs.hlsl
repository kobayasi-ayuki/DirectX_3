// ���_�V�F�[�_���͍\����
struct VS_INPUT
{
	float3 position     : POSITION;  // ���_���W
	float3 sub_position : POSITION1; // �⏕���W
	float3 normal       : NORMAL0;   // �@��
	float3 tangent      : TANGENT0;  // �ڐ�
	float3 binormal     : BINORMAL0; // �]�@��
	float2 texcoord     : TEXCOORD0; // �e�N�X�`��uv���W
	float texcoord2     : TEXCOORD1; // �e�N�X�`��v���W2
	float4 diffuse      : COLOR0;    // �f�B�t�B�[�Y�J���[
	float4 specular     : COLOR1;    // �X�y�L�����J���[
};

// ���_�V�F�[�_�̏o��
struct VS_OUTPUT
{
	float4 diffuse  : COLOR0;		// �f�B�t�B�[�Y�J���[
	float2 texcoord : TEXCOOD0;		// �e�N�X�`��uv���W
	float4 position : SV_POSITION;	// ���W
};

VS_OUTPUT main(VS_INPUT Input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;

	// ���_���W���o��
	output.position = float4(Input.position, 1.0f);

	// �f�B�t�B�[�Y�J���[���o��
	output.diffuse = Input.diffuse;

	// uv���W���o��
	output.texcoord = Input.texcoord;

	return output;
}
