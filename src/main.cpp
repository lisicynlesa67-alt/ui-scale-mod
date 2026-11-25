#include <Geode/Geode.hpp>
#include <Geode/modify/UILayer.hpp>

using namespace geode::prelude;

class $modify(UIScaleLayer, UILayer) {
	bool init(GJBaseGameLayer* layer) {
		if (!UILayer::init(layer)) return false;

		float scale = static_cast<float>(Mod::get()->getSettingValue<double>("ui-scale"));
		if (scale == 1.f) return true;

		// масштабируем вокруг центра экрана
		auto winSize = CCDirector::get()->getWinSize();
		this->ignoreAnchorPointForPosition(false);
		this->setContentSize(winSize);
		this->setAnchorPoint({0.5f, 0.5f});
		this->setPosition(winSize / 2);
		this->setScale(scale);

		return true;
	}
};
