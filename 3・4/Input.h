#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION 0x0800 // DirectInputのバージョン設定
#include <dinput.h>
#include "WinApp.h"

// 入力
class Input {
public:
	// namespace省略
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

	// 初期化
	void Initialize(WinApp* winApp);
	// 更新
	void Update();
	// キー入力
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// キーのトリガーをチェック
	/// </summary>
	/// <param name="keyNumber">キー番号(DIK_0 等)</param>
	/// <returns>トリガーか</returns>
	bool TriggerKey(BYTE keyNumber);

private:
	// キーボードのデバイス
	ComPtr<IDirectInputDevice8> keyboard;

	// DirectInputのインスタンス
	ComPtr<IDirectInput8> directInput;

	// 全キーの状態
	BYTE key[256] = {};

	// 前回の全キーの状態
	BYTE keyPre[256] = {};

	// WindowsAPI
	WinApp* winApp = nullptr;
};