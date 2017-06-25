Helpers
=========

### Description

A php  extension implements the [Laravel's supports functions](https://laravel.com/docs/5.4/helpers).

###  Why create it ?

I want to learn writing c program. Also the extension can be used in normal php develop.

### Functions

#### array_add

The array_add function adds a given key / value pair to the array if the given key doesn't already exist in the array:

```php
  $array = array_add(['name' => 'Desk'], 'price', 100);

  // ['name' => 'Desk', 'price' => 100]
```

### How to use ?

The extension need php7, php7-devel.

```
  phpize

  ./configure

  make && make install

```

Add ` extension = helpers.so` in php.ini file.

### Learning links

1. http://blog.csdn.net/fengye245/article/details/7870501/

1. http://blog.csdn.net/tonysz126/article/details/6993665  
