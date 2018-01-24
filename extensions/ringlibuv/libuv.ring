if iswindows()
	LoadLib("ring_uv.dll")
but ismacosx()
	LoadLib("libringuv.dylib")
but islinux() and not isandroid()
	LoadLib("libringuv.so")
ok

Load "ring_libuv.rh"

func uv_walk oloop, cFunc, oArg
	return uv_walk_2(oLoop,
		uv_callback(oLoop,"walk",cFunc),
		oArg)

func uv_close handle, cFunc
	return uv_close_2(handle,
		uv_callback(handle,"close",cFunc))

func uv_timer_start handle, cFunc, timeout, repeat
	return uv_timer_start_2(handle,
		uv_callback(handle,"timer",cFunc),
		timeout,repeat)

func uv_prepare_start prepare, cFunc
	return uv_prepare_start_2(prepare,
		uv_callback(prepare,"prepare",cFunc))

func uv_check_start check, cFunc
	return uv_check_start_2(check,
		uv_callback(check,"check",cFunc))

func uv_idle_start oObj,cFunc
	return uv_idle_start_2(oObj,
		uv_callback(oObj,"idle",cFunc))

func uv_async_init oloop, async, cFunc
	return uv_async_init_2(oLoop,async,
		uv_callback(oLoop,"async",cFunc))

func uv_poll_start handle, events, cFunc
	return uv_poll_start_2(handle,events,
		uv_callback(handle,"poll",cFunc))

func uv_signal_start signal, cFunc, signum
	return uv_signal_start_2(signal,
		uv_callback(signal,"signal",cFunc),
		signum)

func uv_signal_start_oneshot signal, cFunc, signum
	return uv_signal_start_oneshot_2(signal,
		uv_callback(signal,"signal",cFunc),
		signum)

func uv_shutdown req, handle, cFunc
	return uv_shutdown_2(req,handle,
		uv_callback(req,"shutdown",cFunc))

func uv_listen oObj,nOption,cFunc 
	return uv_listen_2(oObj,nOption,uv_callback(oObj,"connect",cFunc))

func uv_read_start stream, cFunc, cFunc2
	if isstring(cFunc)
		Alloc = uv_callback(stream,"alloc",cFunc)
	else
		Alloc = cFunc	# We expect function pointer (C Pointer)
	ok

	return uv_read_start_2(stream,
		Alloc,
		uv_callback(stream,"read",cFunc2))

func uv_write req, handle, bufs, nbufs, cFunc
	return uv_write_2(req,handle,bufs,nbufs,
		uv_callback(req,"write",cFunc))

func uv_write2 req, handle, bufs, nbufs, send_handle, cFunc
	return uv_write2_2(req,handle,bufs,nbufs,send_handle,
		uv_callback(req,"write",cFunc))

func uv_tcp_connect oConnect,oSocket,oAddr,cFunc 
	return uv_tcp_connect_2(oConnect,oSocket,oAddr,
		uv_callback(oConnect,"connect",cFunc))

func uv_pipe_connect req, handle, name, cFunc
	return uv_pipe_connect_2(req,handle,name,
		uv_callback(req,"connect",cFunc))

func uv_udp_send req, handle, bufs, nbufs, addr, cFunc
	return uv_udp_send_2(req, handle, bufs, nbufs, addr, 
		uv_callback(req,"udp_send",cFunc))

func uv_udp_recv_start handle, cFunc, cFunc2
	return uv_udp_recv_start_2(handle,
		uv_callback(handle,"alloc",cFunc),
		uv_callback(handle,"udp_recev",cFunc))

func uv_fs_event_start handle, cFunc, path, flags
	return uv_fs_event_start_2(handle,
		uv_callback(handle,"fs_event",cFunc),
		path,flags)

func uv_fs_poll_start handle, cFunc, path, interval	
	return uv_fs_poll_start_2(handle,
		uv_callback(handle,"fs_poll",cFunc),
		path, interval)

func uv_fs_close oLoop, req, file, cFunc
	return uv_fs_close_2(oLoop,req,file,
		uv_callback(oLoop,"fs",cFunc))

func uv_fs_open oLoop, req, path, flags, mode, cFunc
	return uv_fs_open_2(oLoop,  req, path, flags, mode,
		uv_callback(oLoop,"fs",cFunc))

func uv_fs_read oLoop, req, file, bufs, nbufs, offset, cFunc
	return uv_fs_read_2(oLoop, req, file, bufs, nbufs, offset,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_unlink oLoop,req, path, cFunc
	return uv_fs_unlink_2(oLoop,req, path,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_write oLoop, req, file, bufs,  nbufs, offset, cFunc
	return uv_fs_write_2( oLoop, req, file, bufs,  nbufs, offset, 
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_mkdir oLoop, req, path, mode, cFunc
	return uv_fs_mkdir_2( oLoop, req, path, mode,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_mkdtemp oLoop, req, tpl, cFunc
	return uv_fs_mkdtemp_2( oLoop, req, tpl,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_rmdir oLoop, req, path, cFunc
	return uv_fs_rmdir_2( oLoop, req, path, 
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_scandir oLoop, req, path, flags, cFunc
	return uv_fs_scandir_2( oLoop, req, path, flags,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_stat oLoop, req, path, cFunc
	return uv_fs_stat_2( oLoop, req, path, 
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_fstat oLoop, req, file, cFunc
	return uv_fs_fstat_2( oLoop, req, file,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_lstat oLoop, req, path, cFunc
	return uv_fs_lstat_2( oLoop, req, path,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_rename oLoop, req, path, new_path, cFunc
	return uv_fs_rename_2( oLoop, req, path, new_path,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_fsync oLoop, req, file, cFunc
	return uv_fs_fsync_2( oLoop, req, file,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_fdatasync oLoop, req, file, cFunc
	return uv_fs_fdatasync_2( oLoop, req, file,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_ftruncate oLoop, req, file, offset, cFunc
	return uv_fs_ftruncate_2( oLoop, req, file, offset,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_copyfile oLoop, req, path, new_path, flags, cFunc
	return uv_fs_copyfile_2( oLoop, req, path, new_path, flags,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_sendfile oLoop, req, out_fd, in_fd, in_offset, length, cFunc
	return uv_fs_sendfile_2( oLoop, req, out_fd, in_fd, in_offset, length,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_access oLoop, req, path, mode, cFunc
	return uv_fs_access_2( oLoop, req, path, mode,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_chmod oLoop, req, path, mode, cFunc
	return uv_fs_chmod_2( oLoop, req, path, mode,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_fchmod oLoop, req, file, mode, cFunc
	return uv_fs_fchmod_2( oLoop, req, file, mode,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_utime oLoop, req, path, atime, mtime, cFunc
	return uv_fs_utime_2( oLoop, req, path, atime, mtime,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_futime oLoop, req, file, atime, mtime, cFunc
	return uv_fs_futime_2( oLoop, req, file, atime, mtime,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_link oLoop, req, path, new_path, cFunc
	return uv_fs_link_2( oLoop, req, path, new_path,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_symlink oLoop, req, path, new_path, flags, cFunc
	return uv_fs_symlink_2( oLoop, req, path, new_path, flags,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_readlink oLoop, req, path, cFunc
	return uv_fs_readlink_2( oLoop, req, path,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_realpath oLoop, req, path, cFunc
	return uv_fs_realpath_2( oLoop, req, path,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_chown oLoop, req, path, uid, gid, cFunc
	return uv_fs_chown_2( oLoop, req, path, uid, gid,
		uv_callback(oLoop,"fs",cFunc))	

func uv_fs_fchown oLoop, req, file, uid, gid, cFunc
	return uv_fs_fchown_2( oLoop, req, file, uid, gid,
		uv_callback(oLoop,"fs",cFunc))	

func uv_queue_work oLoop, req, cFunc, cFunc2
	return uv_queue_work_2(oLoop,req,
		uv_callback(oLoop,"work",cFunc),
		uv_callback(oLoop,"after_work",cFunc2))	

func uv_getaddrinfo oLoop, req, cFunc, node, service, hints
	return uv_getaddrinfo_2(oLoop,req,
		uv_callback(oLoop,"getaddrinfo",cFunc),
		node, service, hints)

func uv_getnameinfo oLoop, req, cFunc, addr, flags
	return uv_getnameinfo_2(oLoop,req,
		uv_callback(oLoop,"getnameinfo",cFunc),
		addr, flags)

func uv_thread_create tid, cFunc, arg
	return uv_thread_create_2(tid,
		uv_callback(tid,"thread",cFunc), arg)


func uv_buf2str oBuf
	return uv_pointer2string(get_uv_buf_t_base(oBuf),
					get_uv_buf_t_len(oBuf))

func uv_str2buf cStr
	buf = new_uv_buf_t()
	set_uv_buf_t_len(buf,len(cStr))
	set_uv_buf_t_base(buf,varptr(:cStr,"char *"))
	return buf
