#include "../includes/ft_memory.h"

static char ft_get_type(INFO *curr, STAT *sb)
{
	if (S_ISFIFO(sb->st_mode))
		return (curr->type = 'p');
	else if (S_ISCHR(sb->st_mode))
		return (curr->type = 'c');
	else if (S_ISDIR(sb->st_mode))
		return (curr->type = 'd');
	else if (S_ISBLK(sb->st_mode))
		return (curr->type = 'b');	
	else if (S_ISLNK(sb->st_mode))
		return (curr->type = 'l');
	else if (S_ISSOCK(sb->st_mode))
		return (curr->type = 's');
	else if (S_ISREG(sb->st_mode))
		return (curr->type = '-');	
	return (curr->type);
}

static void	ft_display_permission(mode_t st_mode)
{
	fpf_printf("%c", st_mode & S_IRUSR ? 'r' : '-');
	fpf_printf("%c", st_mode & S_IWUSR ? 'w' : '-');
	if (st_mode & S_ISUID)
		fpf_printf("%c", st_mode & S_IXUSR ? 's' : 'S');
	else
		fpf_printf("%c", st_mode & S_IXUSR ? 'x' : '-');
	fpf_printf("%c", st_mode & S_IRGRP ? 'r' : '-');
	fpf_printf("%c", st_mode & S_IWGRP ? 'w' : '-');
	if (st_mode & S_ISGID)
		fpf_printf("%c", st_mode & S_IXGRP ? 's' : 'S');
	else
		fpf_printf("%c", st_mode & S_IXGRP ? 'x' : '-');
	fpf_printf("%c", st_mode & S_IROTH ? 'r' : '-');
	fpf_printf("%c", st_mode & S_IWOTH ? 'w' : '-');
	if (st_mode & S_ISVTX)
		fpf_printf("%c", st_mode & S_IXOTH ? 't' : 'T');
	else
		fpf_printf("%c", st_mode & S_IXOTH ? 'x' : '-');
}

INFO *ft_fill_info(STAT *sb)
{
	INFO *info;
	struct passwd *psswd;
	struct group *grp;

	if (!(info = (INFO*)malloc(sizeof(INFO))))
		return	(NULL);
	ft_get_type(info, sb);
	info->nb_link = sb->st_nlink;
	psswd = getpwuid(sb->st_uid);
	grp = getgrgid(sb->st_gid);
	info->uid = psswd->pw_name;
	info->major = ft_itoa((int)((char)((int32_t)(((u_int32_t)(sb->st_rdev) >> 24) & 0xff))));
	info->minor = ft_itoa((int)((char)sb->st_rdev));
	info->guid = grp->gr_name;
	info->size = sb->st_size;
	info->mtime = ctime(&sb->st_mtime);
	return (info);
}

// static void	ft_check_acl_extd(char *path)
// {
// 	char	buff[BUFF_MAX];
// 	ssize_t	nb_xat;
// 	acl_t	p_acl;

// 	if ((nb_xat = listxattr(path, buff, BUFF_MAX, XATTR_NOFOLLOW)))
// 		fpf_printf("@");
// 	else if ((p_acl = acl_get_file(path, ACL_TYPE_EXTENDED)))
// 	{
// 		acl_free((void*)p_acl);
// 		fpf_printf("+");
// 	}
// 	else
// 		fpf_printf(" ");
// }

void ft_display_l(LF *tmp, STAT sb, char *path)
{
	char *buf;

	fpf_printf("%c", tmp->info->type);
	ft_display_permission(sb.st_mode);
	// ft_check_acl_extd(path);
	fpf_printf("  %*d %-*s  %-*s ", g_link_max ,tmp->info->nb_link, g_uid_max ,tmp->info->uid, g_guid_max ,tmp->info->guid);
	if (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode))
		fpf_printf("   %*s, %*s ", g_major_max, tmp->info->major, g_minor_max, tmp->info->minor);
	else 
		fpf_printf(" %*d ", ft_decade(g_size_max), tmp->info->size);
	ft_get_time(sb.st_mtime);
	ft_putstr(tmp->name);
	if (tmp->info->type == 'l')
	{
			buf = ft_strnew(256);
			readlink(path, buf, 256);
			fpf_printf(" -> %s", buf);
			ft_memdel((void*)&buf);
	}
	ft_putchar('\n');
	free(tmp->info);
}