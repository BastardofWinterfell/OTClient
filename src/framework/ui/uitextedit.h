/*
 * Copyright (c) 2010-2012 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef UILINEEDIT_H
#define UILINEEDIT_H

#include "uiwidget.h"

class UITextEdit : public UIWidget
{
public:
    UITextEdit();

    void drawSelf(Fw::DrawPane drawPane);

private:
    void update();

public:
    void setTextHorizontalMargin(int margin);
    void setCursorPos(int pos);
    void setCursorEnabled(bool enable);
    void setTextHidden(bool hidden);
    void setValidCharacters(const std::string validCharacters) { m_validCharacters = validCharacters; }
    void setShiftNavigation(bool enable) { m_shiftNavigation = enable; }
    void setMultiline(bool enable) { m_multiline = enable; }
    void setMaxLength(uint maxLength) { m_maxLength = maxLength; }

    void moveCursor(bool right);
    void appendText(std::string text);
    void appendCharacter(char c);
    void removeCharacter(bool right);

    std::string getDisplayedText();
    int getTextPos(Point pos);
    int getTextHorizontalMargin() { return m_textHorizontalMargin; }
    int getCursorPos() { return m_cursorPos; }
    uint getMaxLength() { return m_maxLength; }
    bool isCursorEnabled() { return m_cursorPos != -1; }
    bool isTextHidden() { return m_textHidden; }
    bool isShiftNavigation() { return m_shiftNavigation; }
    bool isMultiline() { return m_multiline; }

protected:
    virtual void onTextChange(const std::string& text, const std::string& oldText);
    virtual void onFontChange(const std::string& font);
    virtual void onStyleApply(const std::string& styleName, const OTMLNodePtr& styleNode);
    virtual void onGeometryChange(const Rect& oldRect, const Rect& newRect);
    virtual void onFocusChange(bool focused, Fw::FocusReason reason);
    virtual bool onKeyText(const std::string& keyText);
    virtual bool onKeyPress(uchar keyCode, int keyboardModifiers, int autoRepeatTicks);
    virtual bool onMousePress(const Point& mousePos, Fw::MouseButton button);

private:
    void blinkCursor();

    Rect m_drawArea;
    int m_cursorPos;
    Point m_startInternalPos;
    int m_startRenderPos;
    ticks_t m_cursorTicks;
    int m_textHorizontalMargin;
    bool m_textHidden;
    bool m_shiftNavigation;
    bool m_multiline;
    std::string m_validCharacters;
    uint m_maxLength;

    std::vector<Rect> m_glyphsCoords;
    std::vector<Rect> m_glyphsTexCoords;
};

#endif
