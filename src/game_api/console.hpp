#pragma once

#include <deque>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

class SpelunkyConsole
{
  public:
    SpelunkyConsole(class SoundManager* sound_manager);
    ~SpelunkyConsole();

    std::vector<std::string> consume_requires();
    std::deque<struct ScriptMessage> consume_messages();
    const std::deque<ScriptMessage>& get_messages() const;

    bool is_enabled();
    bool is_toggled();

    bool run();
    void draw(struct ImDrawList* dl);
    void render_options();

    void toggle();

    std::string execute(std::string code);

    bool has_new_history() const;
    void set_max_history_size(size_t max_history);
    void save_history(std::string_view path);
    void load_history(std::string_view path);
    void push_history(std::string history_item, std::vector<ScriptMessage> result_item);

    std::string dump_api();

    class LuaConsole* get_impl()
    {
        return m_Impl.get();
    }

    void set_selected_uid(uint32_t uid);
    unsigned int get_input_lines();
    void set_geometry(float x, float y, float w, float h);

  private:
    std::unique_ptr<class LuaConsole> m_Impl;
};
