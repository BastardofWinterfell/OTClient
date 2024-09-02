function translateNetworkError(errcode, connecting, errdesc)
    local text
    if errcode == 111 then
        text = tr('The server is currently down for maintenance.\nPlease try again later.')
    elseif errcode == 110 then
        text = tr('Connection timed out. Either your network or the server is currently offline.')
    elseif errcode == 1 then
        text = tr('Connection failed. The server address does not exist.')
    elseif connecting then
        text = tr('The server is currently down for maintenance.\nPlease try again later.')
    else
        text = tr('Your connection has been lost.\nEither your network or the server is currently offline.')
    end
    --text = text .. ' ' .. tr('(ERROR %d)', errcode)
    return text
end
