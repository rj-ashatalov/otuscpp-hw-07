#pragma once

#include <string>
#include <functional>
#include <map>

namespace Event
{
    static const std::string SEQUENCE_COMPLETE = "suquence_complete";
    static const std::string FIRST_COMMAND = "first_command";
}

class EventDispatcher
{
        using handler_type = std::function<void(std::string)>;

        struct Subscription
        {
            Subscription(const handler_type& handler)
                    : handler(handler)
            {
            }

            handler_type handler;
        };

    public:
        void Subscribe(std::string eventId, handler_type&& handler)
        {

            auto it = _eventIdToHandlerList.find(eventId);
            if (it == _eventIdToHandlerList.end())
            {
                std::tie(it, std::ignore) = _eventIdToHandlerList.emplace(std::piecewise_construct
                        , std::make_tuple(eventId)
                        , std::make_tuple());
            }

            auto&& subscription = std::make_shared<Subscription>(handler);
            it->second.push_back(subscription);
        };

        void UnsubscribeAll(std::string eventId)
        {
            auto it = _eventIdToHandlerList.find(eventId);
            if (it != _eventIdToHandlerList.end())
            {
                _eventIdToHandlerList.erase(it);
            }
        };

        void Dispatch(std::string eventId, std::string message)
        {
            auto it = _eventIdToHandlerList.find(eventId);
            if (it != _eventIdToHandlerList.end())
            {
                for (auto&& subscription: it->second)
                {
                    subscription->handler(message);
                }
            }
        };
    private:
        std::map<std::string, std::vector<std::shared_ptr<Subscription>>> _eventIdToHandlerList;
};


