#include "../inc/EventQueue.h"

Event* EventQueue::pop() {
    if (!ready_tasks.empty()) {
        Event* e = ready_tasks.front();
        ready_tasks.pop();
        return e;
    }


    auto available_sockets = socket_pull.getFreeSockets(5); // change later
    for (auto e: io_events) {
        if (available_sockets.find(e->get_socket()) != available_sockets.end()) {
            e->setReady();
        }
    }

    if (ready_tasks.empty()){
        return pop();
    } else {
        Event* e = ready_tasks.front();
        ready_tasks.pop();
        return e;
    } // Потенційно тут можна просто попнути а не копіпастити код, але не факт
}

bool EventQueue::empty() {
    return io_events.empty() && ready_tasks.empty();
}