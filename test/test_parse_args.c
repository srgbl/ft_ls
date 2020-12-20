#include "ft_ls.h"
#include <assert.h>

void print_paths(t_list	*paths)
{
    while (paths != NULL)
    {
        ft_printf("%s\n", (char*)paths->content);
        paths = paths->next;
    }
}

int main()
{
    uint8_t	options;
	t_list	*paths;

    options = 0;
    paths = NULL;
    char    *args1[] = {"./ft_ls", "-a", "def"};
    parse_args(3, args1, &paths, &options);
    assert(ft_lstsize(paths) == 1);

    options = 0;
    paths = NULL;
    char *args2[] = {"./ft_ls", "def", "-a"};
    parse_args(3, args2, &paths, &options);
    assert(ft_lstsize(paths) == 1);

    options = 0;
    paths = NULL;
    char *args3[] = {"./ft_ls", "-a"};
    parse_args(3, args3, &paths, &options);
    assert(ft_lstsize(paths) == 1); //"."

    ft_printf("All tests completed\n");
    return (0);
}
