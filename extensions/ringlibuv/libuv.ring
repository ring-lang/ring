if iswindows()
	LoadLib("ring_uv.dll")
but ismacosx()
	LoadLib("libring_uv.dylib")
but islinux() and not isandroid()
	LoadLib("libring_uv.so")
ok

Load "ring_libuv.rh"

# More Constants
	UV_EVENTPARA_STATUS = 2
	UV_EVENTPARA_SIZE   = 2
	UV_EVENTPARA_BUFFER = 3

func uv_walk oloop, cFunc, oArg
	cCall = uv_callback(oLoop,"walk",cFunc)
	return uv_walk_2(oLoop,cCall,oArg)

func uv_close handle, cFunc
	cCall = uv_callback(handle,"close",cFunc)
	return uv_close_2(handle,cCall)

func uv_timer_start handle, cFunc, timeout, repeat
	cCall = uv_callback(handle,"timer",cFunc)
	return uv_timer_start_2(handle,cCall,timeout,repeat)

func uv_prepare_start prepare, cFunc
	cCall = uv_callback(prepare,"prepare",cFunc)
	return uv_prepare_start_2(prepare,cCall)

func uv_check_start check, cFunc
	cCall = uv_callback(check,"check",cFunc)
	return uv_check_start_2(check,cCall)

func uv_idle_start oObj,cFunc
	cCall = uv_callback(oObj,"idle",cFunc)
	return uv_idle_start_2(oObj,cCall)

func uv_async_init oloop, async, cFunc
	cCall = uv_callback(oLoop,"async",cFunc)
	return uv_async_init_2(oLoop,async,cCall)

func uv_poll_start handle, events, cFunc
	cCall = uv_callback(handle,"poll",cFunc)
	return uv_poll_start_2(handle,events,cCall)

func uv_signal_start signal, cFunc, signum
	cCall = uv_callback(signal,"signal",cFunc)
	return uv_signal_start_2(signal,cCall,signum)

func uv_signal_start_oneshot signal, cFunc, signum
	cCall = uv_callback(signal,"signal",cFunc)
	return uv_signal_start_oneshot_2(signal,cCall,signum)

func uv_shutdown req, handle, cFunc
	cCall = uv_callback(req,"shutdown",cFunc)
	return uv_shutdown_2(req,handle,cCall)

func uv_listen oObj,nOption,cFunc 
	cCall = uv_callback(oObj,"connect",cFunc)
	return uv_listen_2(oObj,nOption,cCall)

func uv_read_start stream, cFunc, cFunc2
	if isstring(cFunc)
		Alloc = uv_callback(stream,"alloc",cFunc)
	else
		Alloc = cFunc	# We expect function pointer (C Pointer)
	ok
	cCall = uv_callback(stream,"read",cFunc2)
	return uv_read_start_2(stream,Alloc,cCall)

func uv_write req, handle, bufs, nbufs, cFunc
	cCall = uv_callback(req,"write",cFunc)
	return uv_write_2(req,handle,bufs,nbufs,cCall)

func uv_write2 req, handle, bufs, nbufs, send_handle, cFunc	
	cCall = uv_callback(req,"write",cFunc)
	return uv_write2_2(req,handle,bufs,nbufs,send_handle,cCall)

func uv_tcp_connect oConnect,oSocket,oAddr,cFunc
	cCall = uv_callback(oConnect,"connect",cFunc) 
	return uv_tcp_connect_2(oConnect,oSocket,oAddr,cCall)

func uv_pipe_connect req, handle, name, cFunc
	cCall = uv_callback(req,"connect",cFunc)
	return uv_pipe_connect_2(req,handle,name,cCall)

func uv_udp_send req, handle, bufs, nbufs, addr, cFunc
	cCall = uv_callback(req,"udp_send",cFunc)
	return uv_udp_send_2(req, handle, bufs, nbufs, addr, cCall)

func uv_udp_recv_start handle, cFunc, cFunc2
	cCall  = uv_callback(handle,"alloc",cFunc)
	cCall2 = uv_callback(handle,"udp_recev",cFunc)
	return uv_udp_recv_start_2(handle,cCall,cCall2)

func uv_fs_event_start handle, cFunc, path, flags
	cCall = uv_callback(handle,"fs_event",cFunc)
	return uv_fs_event_start_2(handle,cCall,path,flags)

func uv_fs_poll_start handle, cFunc, path, interval	
	cCall = uv_callback(handle,"fs_poll",cFunc)
	return uv_fs_poll_start_2(handle,cCall,path, interval)

func uv_fs_close oLoop, req, file, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_close_2(oLoop,req,file,cCall)

func uv_fs_open oLoop, req, path, flags, mode, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_open_2(oLoop,  req, path, flags, mode,cCall)

func uv_fs_read oLoop, req, file, bufs, nbufs, offset, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_read_2(oLoop, req, file, bufs, nbufs, offset,cCall)	

func uv_fs_unlink oLoop,req, path, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_unlink_2(oLoop,req, path,cCall)	

func uv_fs_write oLoop, req, file, bufs,  nbufs, offset, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_write_2( oLoop, req, file, bufs,  nbufs, offset, cCall)	

func uv_fs_mkdir oLoop, req, path, mode, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_mkdir_2( oLoop, req, path, mode,cCall)	

func uv_fs_mkdtemp oLoop, req, tpl, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_mkdtemp_2( oLoop, req, tpl,cCall)	

func uv_fs_rmdir oLoop, req, path, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_rmdir_2( oLoop, req, path, cCall)	

func uv_fs_scandir oLoop, req, path, flags, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_scandir_2( oLoop, req, path, flags,cCall)	

func uv_fs_stat oLoop, req, path, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_stat_2( oLoop, req, path, cCall)	

func uv_fs_fstat oLoop, req, file, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_fstat_2( oLoop, req, file,cCall)	

func uv_fs_lstat oLoop, req, path, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_lstat_2( oLoop, req, path,	cCall)	

func uv_fs_rename oLoop, req, path, new_path, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_rename_2( oLoop, req, path, new_path,cCall)	

func uv_fs_fsync oLoop, req, file, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_fsync_2( oLoop, req, file,	cCall)	

func uv_fs_fdatasync oLoop, req, file, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_fdatasync_2( oLoop, req, file,cCall)	

func uv_fs_ftruncate oLoop, req, file, offset, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_ftruncate_2( oLoop, req, file, offset,cCall)	

func uv_fs_copyfile oLoop, req, path, new_path, flags, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_copyfile_2( oLoop, req, path, new_path, flags,cCall)	

func uv_fs_sendfile oLoop, req, out_fd, in_fd, in_offset, length, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_sendfile_2( oLoop, req, out_fd, in_fd, in_offset, length,cCall)	

func uv_fs_access oLoop, req, path, mode, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_access_2( oLoop, req, path, mode,cCall)	

func uv_fs_chmod oLoop, req, path, mode, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_chmod_2( oLoop, req, path, mode,cCall)	

func uv_fs_fchmod oLoop, req, file, mode, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_fchmod_2( oLoop, req, file, mode,cCall)	

func uv_fs_utime oLoop, req, path, atime, mtime, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_utime_2( oLoop, req, path, atime, mtime,cCall)	

func uv_fs_futime oLoop, req, file, atime, mtime, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_futime_2( oLoop, req, file, atime, mtime,cCall)	

func uv_fs_link oLoop, req, path, new_path, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_link_2( oLoop, req, path, new_path,cCall)	

func uv_fs_symlink oLoop, req, path, new_path, flags, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_symlink_2( oLoop, req, path, new_path, flags,cCall)	

func uv_fs_readlink oLoop, req, path, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_readlink_2( oLoop, req, path,cCall)	

func uv_fs_realpath oLoop, req, path, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_realpath_2( oLoop, req, path,cCall)	

func uv_fs_chown oLoop, req, path, uid, gid, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_chown_2( oLoop, req, path, uid, gid,cCall)	

func uv_fs_fchown oLoop, req, file, uid, gid, cFunc
	cCall = uv_callback(oLoop,"fs",cFunc)
	return uv_fs_fchown_2( oLoop, req, file, uid, gid,cCall)	

func uv_queue_work oLoop, req, cFunc, cFunc2
	cCall  = uv_callback(oLoop,"work",cFunc)
	cCall2 = uv_callback(oLoop,"after_work",cFunc2)
	return uv_queue_work_2(oLoop,req,cCall,	cCall2)	

func uv_getaddrinfo oLoop, req, cFunc, node, service, hints
	cCall = uv_callback(oLoop,"getaddrinfo",cFunc)
	return uv_getaddrinfo_2(oLoop,req,cCall,node, service, hints)

func uv_getnameinfo oLoop, req, cFunc, addr, flags
	cCall = uv_callback(oLoop,"getnameinfo",cFunc)
	return uv_getnameinfo_2(oLoop,req,cCall,addr, flags)

func uv_thread_create tid, cFunc
	cCall = uv_callback(tid,"thread",cFunc)
	return uv_thread_create_2(tid,cCall, tid)


func uv_buf2str oBuf
	oBase = get_uv_buf_t_base(oBuf)
	nSize = get_uv_buf_t_len(oBuf)
	return uv_pointer2string(oBase,nSize)

