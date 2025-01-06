#pragma once

// スプライト共通部
class SpriteCommon {
public: // メンバ関数
	// 初期化
	void Initialize(DirectXCommon* dxCommon);

	DirectXCommon* GetDxCommon() const { return dxCommon_; }

	// 共通描画設定
	void DrawCommon();

private:
	// ルートシグネチャの作成
	void MakeRootSignature();
	// グラフィックスパイプラインの生成
	void MakeGraphicsPipeline();

	DirectXCommon* dxCommon_;
};