var path = require('path'),
    rootPath = path.normalize(__dirname + '/..'),
    env = process.env.NODE_ENV || 'development';

var config = {
  development: {
    root: rootPath,
    app: {
      name: 'virusone'
    },
    port: 3000,
    db: 'mongodb://localhost/virusone-development'
  },

  test: {
    root: rootPath,
    app: {
      name: 'virusone'
    },
    port: 3000,
    db: 'mongodb://localhost/virusone-test'
  },

  production: {
    root: rootPath,
    app: {
      name: 'virusone'
    },
    port: 3000,
    db: 'mongodb://localhost/virusone-production'
  }
};

module.exports = config[env];
