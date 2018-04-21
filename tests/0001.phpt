--TEST--
Test #1
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
class ContainerNotFoundException extends Exception implements Psr\Container\NotFoundExceptionInterface
{
}

class Container implements Psr\Container\ContainerInterface
{
    public function get($id)
    {
        throw new ContainerNotFoundException();
    }

    public function has($id)
    {
        return false;
    }
}

$c = new Container();
try {
    $c->get('xxx');
}
catch (ContainerNotFoundException $e) {
    var_dump($e instanceof Psr\Container\NotFoundExceptionInterface);
    var_dump($e instanceof Psr\Container\ContainerExceptionInterface);
}

?>
--EXPECT--
bool(true)
bool(true)

