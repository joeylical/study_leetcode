-- local current_file_dir = vim.fn.expand('%:p:h')
vim.api.nvim_del_keymap('n', '<c-t>')
vim.api.nvim_del_keymap('n', '<m-t>')
function _cdir()
    return vim.fn.expand('%:p:h')
end
function _tcmd()
    return 'ToggleTerm dir="' .. _cdir() .. '"'
end
function _toggle()
    vim.cmd(_tcmd())
end
function _toggle_f()
    vim.cmd(_tcmd() .. 'direction=float')
end
vim.api.nvim_set_keymap('n', '<c-t>', ':lua _toggle()<cr>', {})
vim.api.nvim_set_keymap('n', '<m-t>', ':lua _toggle_f()<cr>', {})
