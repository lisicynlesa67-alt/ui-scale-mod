#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;

class $modify(UIScalePlayLayer, PlayLayer) {
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();

		float scale = static_cast<float>(Mod::get()->getSettingValue<double>("ui-scale"));
		log::info("UI Scale: applying {}", scale);
		Notification::create(fmt::format("UI Scale: {}", scale), NotificationIcon::Info, 1.5f)->show();

		if (!m_uiLayer) return;

		auto winSize = CCDirector::get()->getWinSize();
		m_uiLayer->ignoreAnchorPointForPosition(false);
		m_uiLayer->setContentSize(winSize);
		m_uiLayer->setAnchorPoint({0.5f, 0.5f});
		m_uiLayer->setPosition(winSize / 2);
		m_uiLayer->setScale(scale);
	}
};
